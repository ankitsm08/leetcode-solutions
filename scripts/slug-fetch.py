import json
import os
import re
import sys
import time
from pathlib import Path

CACHE_DIR = Path.home() / ".cache" / "leetcode"
CACHE_DIR.mkdir(parents=True, exist_ok=True)

PROBLEM_MAP_CACHE = CACHE_DIR / "problem_map.json"
CACHE_TTL = 24 * 3600

PROBLEMS_API = "https://leetcode.com/api/problems/all/"
HEADERS = {
  "User-Agent": "Mozilla/5.0",
  "Referer": "https://leetcode.com/problemset/all/",
}


def fetch_problem_map():
  import requests

  if PROBLEM_MAP_CACHE.exists():
    age = time.time() - PROBLEM_MAP_CACHE.stat().st_mtime
    if age < CACHE_TTL:
      with open(PROBLEM_MAP_CACHE, "r", encoding="utf-8") as f:
        return json.load(f)

  r = requests.get(PROBLEMS_API, headers=HEADERS, timeout=20)
  r.raise_for_status()
  data = r.json()

  mapping = {
    str(q["stat"]["frontend_question_id"]): q["stat"]["question__title_slug"] for q in data["stat_status_pairs"]
  }

  with open(PROBLEM_MAP_CACHE, "w", encoding="utf-8") as f:
    json.dump(mapping, f, indent=2)

  return mapping


def rename_folders(base_dir):
  id_to_slug = fetch_problem_map()
  pattern = re.compile(r"^(\d+)$")

  for name in os.listdir(base_dir):
    old_path = os.path.join(base_dir, name)
    if not os.path.isdir(old_path):
      continue

    m = pattern.match(name)
    if not m:
      continue

    num = m.group(1)
    slug = id_to_slug.get(num)
    if not slug:
      continue

    new_name = f"{num}-{slug}"
    new_path = os.path.join(base_dir, new_name)

    if not os.path.exists(new_path):
      os.rename(old_path, new_path)
      print(f"{name} → {new_name}")


if __name__ == "__main__":
  folder = sys.argv[1] if len(sys.argv) > 1 else input("Folder: ").strip()
  rename_folders(folder)
  print("Slug fetching done")
