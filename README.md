This document is written in `markdown`, you can see a fully-rendered
version by opening `README.html` in a web browser, or by visiting https://github.com/tjysdsg/usage-of-the-recovery-block-for-multi-version-sorting/blob/master/README.md

# Source code

## `src/`
In `src/` directory, `bubble_sort` and `heap_sort` along with their mutants
are implemented in `sort.h/.cpp`. The `acceptance_test` function is
implemented in `acceptance_test.h/.cpp`. In addition, `test_sort` function
is implemented for the tests in `tests/` directory.

## `tests`

Basic tests for two sorting algorithms and their mutants are implemented
here.

## `demo`

This directory contains code using recovery block to implement fault
tolerance.

# Build instructions

## Prerequisites

- CMake
- a C++ compiler *although the program is mostly written in C, I used some C++ features, so it probably won't compile using a pure C compiler*


This project uses `CMake` build system.

To build the project, go to the project root:

```shell script
[user@machine:~/recovery-block-for-multi-version-sorting]$ cmake .
[user@machine:~/recovery-block-for-multi-version-sorting]$ make
```

The produced binaries, `demo` and `test`, are in `bin/` directory.

**This project is built and tested on Linux, but it should work across platform,
if not, please contact me**

# How to run

- `demo`: Build the project, and run `bin/demo`.
- `test`: Build the project, and run `bin/test`.

# How this works

Two sorting algorithms, bubble sorting and heap sorting, and their "mutants"
(to see how mutants are mutated, search for `FIXME` keyword in `src/sort.cpp`)
are implemented. Then in `demo/main.cpp`, the mutated version of bubble sort
is first used as the primary implementation, if it fails (which it will), `heap_sort`
is used as the alternative implementation. If yet it fails again, the program aborts and halt.
The detailed calling history is printed to standard output.

The reason not to use the normal version of bubble sort is that it never fails (as long
as the input is valid), so it cannot fulfill the purpose of implementing software fault tolerance.

Also, you can uncomment the first line of `demo/main.cpp`:
```C++
#define N_VERSION
```
and rebuild the project to see a more general implementation of N-version recovery block.
