*This project has been created as part of the 42 curriculum by ndwairi, dlababne.*

# push_swap

## Description

**push_swap** is an algorithmic project from the 42 curriculum that challenges you to sort a stack of unique integers using two stacks (`a` and `b`) and a restricted set of stack operations, aiming to produce the shortest possible sequence of instructions.

This implementation evaluates the initial disorder of the input stack and supports multiple sorting strategies (`--simple`, `--medium`, `--complex`, and `--adaptive`), alongside a `--bench` mode to inspect operation counts and disorder metrics.

## Instructions

### Compilation

Use the provided `Makefile` to compile the project:

```bash
make
```

Additional Makefile rules:
- `make clean`: Removes object files (`.o`).
- `make fclean`: Removes object files and the `push_swap` executable.
- `make re`: Recompiles the project from scratch.

### Execution

Run the program by passing a list of integers as separate arguments or as a single quoted string:

```bash
./push_swap 4 1 3 2
./push_swap "4 1 3 2"
```

#### Optional Flags

- `--simple`: Forces the O(n^2) simple sorting strategy (optimized small-size sort and min-extraction / insertion).
- `--medium`: Forces the O(n*sqrt(n)) chunk-based sorting strategy.
- `--complex`: Forces the O(n log n) radix sort strategy using binary bit-shifting.
- `--adaptive` *(default)*: Automatically selects the optimal strategy based on the input size and disorder percentage.
- `--bench`: Outputs performance metrics (disorder percentage, chosen strategy, total operations, and individual operation counts) to `stderr`.

Example with flags and checker verification:

```bash
ARG="4 67 3 87 23"; ./push_swap --bench $ARG | ./checker_linux $ARG
```

## Algorithms & Design Choices

1. **Disorder Calculation**: Before sorting, the program computes the inversion ratio (disorder percentage) of stack `a` to determine how far the input is from being sorted.
2. **Simple Strategy O(n^2)**: Uses dedicated hardcoded minimal-move logic for 2 to 5 elements, and repeated minimum-element extraction to stack `b` followed by pushing back to stack `a` for larger inputs under `--simple`.
3. **Medium Strategy O(n*sqrt(n))**: Distributes indexed elements into dynamically sized chunks from stack `a` to stack `b` (using `rb` to position smaller values within each window), then pushes elements back to stack `a` in descending order by rotating via the shortest path (`rb` vs `rrb`).
4. **Complex Strategy O(n log n)**: Normalizes values into zero-based ranks and applies base-2 LSD Radix Sort across bit positions, separating `0` bits to stack `b` (`pb`) and keeping `1` bits in stack `a` (`ra`) before recombining.
5. **Adaptive Strategy**: Routes already-sorted inputs to `0` operations, small stacks (n less than or equal to 5) to the dedicated small-sort routines, and selects between simple, chunk, and radix strategies depending on the measured disorder threshold.

## Resources

- **42 Subject Documentation**: `push_swap` project specification and evaluation guidelines.
- **Sorting Algorithms**:
  - Radix Sort (Least Significant Digit binary implementation)
  - Chunk-based range partitioning on two-stack structures
- **Unix & C References**: Linux `man` pages (`write`, `malloc`, `free`, `exit`) and Valgrind Memcheck documentation.

### Use of AI

We used Claude (Anthropic) as a tutor and reviewer, not as a code generator
for the core of the project:

- **Roadmap**: it helped us understand the project, the order in which to
  build it (parsing, stacks, operations, strategies, `main`), and which
  algorithm families fit each level (insertion, chunks, radix sort).
- **Explanations**: it explained how cost-based insertion, chunk sorting and
  radix sort work, before we implemented them ourselves.
- **Code review**: we showed it our code and it pointed out bugs that we then
  fixed (argument order of `pa`/`pb`, an uninitialized variable in
  `reverse_rotate`, the case of 4 elements in the simple strategy, option
  flags being parsed as numbers, error output).
- **README and Makefile**: it helped us structure the README and the Makefile.

The algorithms and `main.c` were written by us, and we tested them
ourselves. Both of us can explain any part of the code.