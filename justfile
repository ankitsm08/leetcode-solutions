set shell := ["bash", "-eu", "-o", "pipefail", "-c"]

# list available recipes
default:
    @just --list

# setup python venv
venv:
    ls .venv || uv venv --python=3.14
    uv pip install requests markdownify pandas numpy

# format files
format:
    fd -tf -e md -e js -e ts -e jsx -e tsx -e json -e html -e css \
      -X prettier --write --color

    fd -tf -e c -e cpp -e h -e hpp -e hh \
      -X clang-format -i

    fd -tf -e py -X ruff check --fix --color always
    fd -tf -e py -X ruff format --color always

    fd -tf -e rs -X env FORCE_COLOR=1 rustfmt

    fd -tf -e java -X google-java-format -i

# create ONE new problem + fetch
new num:
    mkdir -p problems/$(printf "%04d" {{ num }})
    @just fetch

# fetch slugs and problem data
fetch:
    .venv/bin/python scripts/slug-fetch.py problems/
    .venv/bin/python scripts/problem-fetch.py problems/
    @just format
