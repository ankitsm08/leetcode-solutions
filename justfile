set shell := ["bash", "-eu", "-o", "pipefail", "-c"]

# list available recipes
default:
    @just --list

# setup python venv
venv:
    @echo "==> Creating venv..."
    ls .venv || uv venv --python=3.14
    uv pip install requests markdownify pandas numpy

format-md num="":
    @echo "==> Formatting Markdown files..."
    fd -tf -e md {{ if num == "" { "" } else { "-p problems/$(printf '%04d' " + num + ")" } }} \
      -X prettier --write --color

format-cpp:
    @echo "==> Formatting C/C++ files..."
    fd -tf -e c -e cpp -e h -e hpp -e hh \
      -X clang-format -i

format-py:
    @echo "==> Formatting Python files..."
    fd -tf -e py -X ruff check --fix --color always
    fd -tf -e py -X ruff format --color always

format-web:
    @echo "==> Formatting Web files..."
    fd -tf -e js -e ts -e jsx -e tsx -e json -e html -e css \
      -X prettier --write --color

format-rs:
    @echo "==> Formatting Rust files..."
    fd -tf -e rs -X env FORCE_COLOR=1 rustfmt

format-java:
    @echo "==> Formatting Java files..."
    fd -tf -e java -X google-java-format -i

# format all files
format-all:
    @echo "==> Formatting all files..."
    @just format-md
    @just format-cpp
    @just format-py
    @just format-web
    @just format-rs
    @just format-java

# create ONE new problem + fetch
new num:
    @echo "==> Creating new problem..."
    @n=$(printf "%04d" {{ num }}); \
    if compgen -G "problems/$n*/" > /dev/null; then \
      echo "** Problem $n already exists, skipping directory creation."; \
      exit 0; \
    fi; \
    mkdir "problems/$n";
    @echo "==> Created problem directory."

    just fetch
    just format-md {{ num }}

# fetch slugs and problem data
fetch:
    @echo "==> Fetching slugs..."
    .venv/bin/python scripts/slug-fetch.py problems/
    @echo "==> Fetching problem data..."
    .venv/bin/python scripts/problem-fetch.py problems/
