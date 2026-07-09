# CS1 C++ — CU Boulder / RRCC

A personal practice repository for **CS1: Introduction to Programming in C++**. The goal is not to collect finished assignments, but to build real skill through deliberate practice — loops, functions, arrays, recursion, pass-by-reference, and eventually object-oriented design.

Every file here is something I wrote (or am writing) by hand. The comments in each file are the assignment spec; the code is mine.

---

## How I use Cursor

I treat Cursor as a **patient tutor**, not an answer machine.

A project rule in `.cursor/rules/cs1-cpp-tutor.mdc` keeps the AI in tutor mode: it diagnoses compile errors and logic bugs, asks guiding questions, and gives minimal hints unless I explicitly ask for a full solution. That matters because the learning happens when I trace an example, fix an off-by-one error, or reason about why `int&` changes the caller's variable — not when code gets pasted in for me.

**Typical workflow:**

1. Open a practice file and read the comment prompts at the top.
2. Answer the "think first" questions in comments (loop boundaries, base cases, what `size` means).
3. Write the code myself from scratch — no pre-filled stubs.
4. Compile locally and run small tests from `main()` or `runTests()`.
5. Ask Cursor when I'm stuck: *"Does this work?"*, *"Why does this assert fail?"*, or *"What's wrong with my shift loop?"*
6. Fix it, re-run, and move on.

The rule also nudges **defensive programming**: checking `size` before loops, handling edge cases, and documenting what a function returns when input is invalid. That habit carries over to real codebases where bad data is normal.

---

## Repository layout

### `week10/` — Foundations

Early work on control flow and functions. Mostly complete.

| File | Topics |
|------|--------|
| `loop_practice.cpp` | `for` / `while` boundaries, accumulation, arrays, nested loops, iterative `factorial` |
| `function_practice.cpp` | Functions, conditionals, strings, functions calling functions |
| `dice_roller.cpp` | Small program combining arrays and random values |

### `week11/` — Current track

Deeper practice: arrays with functions, recursion, references, and array mutation (shift loops).

| File | Topics |
|------|--------|
| `array_functions_practice.cpp` | Array helpers (`sumArray`, `maxValue`, `findMinMax`), light `assert` testing |
| `recursion_worksheet.cpp` | Trace base cases in comments first, then recursive implementations |
| `recursion-mini/` | Menu-driven program applying recursion (`factorial`, `power`, etc.) |
| `pass_by_reference.cpp` | `int&` out-parameters, updating `size` by reference |
| `shift_loop_drill.cpp` | Shift-left / shift-right loops, `removeFirst`, `insertAt` |
| `overloading_drill.cpp` | Function overloading practice |

**Suggested order:** array functions → recursion worksheet → recursion mini → pass by reference → shift loop drill → overloading.

### `logging/` — Applied practice

A small multi-file project for structured logging and array auditing. Uses headers, separate compilation, and helpers that mirror patterns from the weekly drills — useful for seeing how CS1 concepts scale into a slightly larger program.

---

## Practice file format

- **Prompts are comments only.** There are no pre-written function bodies or `TODO` skeletons to fill in.
- **I type every line.** Stubs would shortcut the thinking that the prompts are designed to force.
- **Specs live in the comments.** When something looks wrong, the comment block is the source of truth.
- **Tests are simple.** `#include <cassert>` and a `runTests()` function are enough at this level — uncomment one assert at a time.

---

## Building and running

From any source file's directory:

```bash
g++ -std=c++17 -Wall -o program_name source_file.cpp
./program_name
```

For multi-file projects (e.g. `logging/`), compile all `.cpp` files together or build with a simple script.

Flags used consistently across the repo:

- `-std=c++17` — course-standard C++
- `-Wall` — catch common mistakes early

---

## What comes next

Week 11 wraps up references, shifting, and overloading. After that, the plan is a **small OOP project** — multiple classes with member functions — still written by hand, still tutored through Cursor.

---

## Course context

**CS1 — Introduction to Programming**  
CU Boulder / Red Rocks Community College (RRCC)

This repo is my working notebook for that course: progress over perfection, one concept at a time.
