import json
import os
import re
import sys
import unicodedata
from pathlib import Path

CACHE_DIR = Path.home() / ".cache" / "leetcode"
CACHE_DIR.mkdir(parents=True, exist_ok=True)

PROBLEM_CACHE_DIR = CACHE_DIR / "problems"
PROBLEM_CACHE_DIR.mkdir(exist_ok=True)

GRAPHQL_API = "https://leetcode.com/graphql"
HEADERS = {
  "User-Agent": "Mozilla/5.0",
  "Referer": "https://leetcode.com/problemset/all/",
}

WEB_GARBAGE = re.compile(
  r"[\u0000-\u0008\u000B\u000C\u000E-\u001F]"
  r"|[\u007F]"
  r"|[\u00A0\u00AD]"
  r"|[\u200B-\u200F]"
  r"|[\u202A-\u202E]"
  r"|[\u2060-\u206F]"
  r"|[\uFEFF]"
)


def clean_markdown(text: str) -> str:
  text = unicodedata.normalize("NFKC", text)
  text = WEB_GARBAGE.sub("", text)
  return text.strip()


def fetch_problem_markdown(slug: str):
  import requests
  from markdownify import markdownify as md

  cache_file = PROBLEM_CACHE_DIR / f"{slug}.json"

  if cache_file.exists():
    with open(cache_file, "r", encoding="utf-8") as f:
      cached = json.load(f)
      return cached["title"], cached["body"]

  query = {
    "query": """
        query questionData($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            title
            content
          }
        }
        """,
    "variables": {"titleSlug": slug},
  }

  r = requests.post(GRAPHQL_API, json=query, headers=HEADERS, timeout=20)
  r.raise_for_status()

  q = r.json()["data"]["question"]

  # skip locked/premium or unavailable
  if q["content"] is None:
    return q["title"], None

  body_md = md(q["content"], heading_style="ATX").strip()
  body_md = clean_markdown(body_md)

  payload = {"title": q["title"], "body": body_md}
  with open(cache_file, "w", encoding="utf-8") as f:
    json.dump(payload, f, indent=2)

  return payload["title"], payload["body"]


def process_folders(base_dir: str):
  for name in os.listdir(base_dir):
    path = os.path.join(base_dir, name)
    if not os.path.isdir(path):
      continue

    if "-" not in name:
      continue

    _num, slug = name.split("-", 1)
    md_path = os.path.join(path, "problem.md")

    if os.path.exists(md_path) and os.path.getsize(md_path) > 0:
      continue  # already populated

    title, body = fetch_problem_markdown(slug)
    url = f"https://leetcode.com/problems/{slug}/"

    if body is None:
      body = "> Problem content unavailable via LeetCode GraphQL API (locked/premium or unreleased)."
      print(f"WARNING: no content for {name}; wrote placeholder")

    with open(md_path, "w", encoding="utf-8") as f:
      f.write(f"{url}\n\n# {title}\n\n{body}")

    print(f"Updated problem.md for {name}")


if __name__ == "__main__":
  folder = sys.argv[1] if len(sys.argv) > 1 else input("Folder: ").strip()
  process_folders(folder)
  print("Problem fetching done")
