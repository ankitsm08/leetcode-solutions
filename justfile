set shell := ["bash", "-eu", "-o", "pipefail", "-c"]

default:
    @just --list

venv:
    ls .venv || uv venv --python=3.14
    uv pip install requests markdownify pandas numpy

new num:
    mkdir -p problems/$(printf "%04d" {{ num }})
    @just fetch

fetch:
    .venv/bin/python scripts/slug-fetch.py problems/
