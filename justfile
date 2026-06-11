set shell := ["bash", "-eu", "-o", "pipefail", "-c"]

# list available recipes
default:
    @just --list

# setup python venv
venv:
    ls .venv || uv venv --python=3.14
    uv pip install requests markdownify pandas numpy

format-md:
    fd -tf -e md -X prettier --write --color

format-md-num num:
    fd -tf -e md -p problems/$(printf "%04d" "{{ num }}") \
      -X prettier --write --color

format-cpp:
    fd -tf -e c -e cpp -e h -e hpp -e hh \
      -X clang-format -i

format-py:
    fd -tf -e py -X ruff check --fix --color always
    fd -tf -e py -X ruff format --color always

format-web:
    fd -tf -e js -e ts -e jsx -e tsx -e json -e html -e css \
      -X prettier --write --color

format-rs:
    fd -tf -e rs -X env FORCE_COLOR=1 rustfmt

format-java:
    fd -tf -e java -X google-java-format -i

# format all files
format-all:
    @just format-md
    @just format-cc
    @just format-py
    @just format-web
    @just format-rs
    @just format-java

# create ONE new problem + fetch
new num:
    mkdir -p problems/$(printf "%04d" {{ num }})
    @just fetch
    @just format-md-num {{ num }}

# fetch slugs and problem data
fetch:
    .venv/bin/python scripts/slug-fetch.py problems/
    .venv/bin/python scripts/problem-fetch.py problems/
