# LeetCode Solutions

My personal collection of LeetCode solutions. Everything is organized per problem, with automated tooling to fetch problem descriptions and format code.

I originally started solving in `C` to force myself to learn the fundamentals, but now I mostly use `C++` for actual competitive programming. I'll occasionally use `Python` for speed solving, `Rust` or `Java` to keep my syntax fresh, and `TypeScript` only when a problem explicitly forces me to.

## Repository Structure

- Each problem lives in its own folder
- `problem.md` contains:
  - the LeetCode URL
  - the full problem statement
- `notes.md` contains:
  - my notes on the problem/solution

```text
problems/
  ├── 0001-two-sum/
  │   ├── notes.md
  │   ├── problem.md
  │   └── solution.cpp
  ├── 0206-reverse-linked-list/
  │   ├── problem.md
  │   ├── solution.c
  │   └── solution.cpp
scripts/
  ├── slug-fetch.py
  └── problem-fetch.py
```

## Tooling & Automation

I use a `justfile` along with `fd` and various language formatters to automate repo maintenance.

### Commands

Creates a virtual environment and installs the required Python dependencies for the scripts:

```bash
just venv
```

Fetches missing LeetCode slugs, downloads/sanitizes the problem statements, and updates `problem.md` files where necessary.

```bash
just fetch

```

Creates a new directory for the problem, resolves the LeetCode slug, and fetches the problem statement. (e.g., `just new 123`)

```bash
just new <problem_number>
```

Runs the appropriate formatters on all supported files (respecting `.gitignore`):

```bash
just format-all
```

Formatters used are:

- `prettier` (Markdown, JS/TS, JSON, HTML, CSS)
- `clang-format` (C/C++)
- `ruff` (Python)
- `rustfmt` (Rust)
- `google-java-format` (Java)

## License

**MIT License**

**Disclaimer:** The problem statements and descriptions (problem.md) are the intellectual property of **LeetCode**. The license below only applies to my personal solutions, notes, and automation scripts.
