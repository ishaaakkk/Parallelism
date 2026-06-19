 # Parallel Mandelbrot: Comparative Study of Task Analysis, OpenMP Decompositions, and Scheduling Strategies

 This repository contains multiple implementations of the Mandelbrot set renderer used to study task decomposition, OpenMP parallelization approaches, and scheduling strategies. It collects sequential (Tareador-instrumented) code, OpenMP iterative and recursive implementations, and C++ scheduling experiments (block / cyclic / block-cyclic).

 **Index**
 - [Source: Lab 3 — Sequential & Tareador](src/lab3-sequential-tareador/)
 - [Source: Lab 4 — OpenMP variants](src/lab4-openmp-variants/)
 - [Source: Lab 5 — Scheduling strategies (C++)](src/lab5-scheduling-strategies/)
 - [Assignment specs and PDFs](assignment-specs/)
 - [Build system and Makefiles](build/)
 - [Examples and sample images](examples/)
 - [Helper scripts](scripts/)
 - [Documentation and notes](docs/)

 ---

 ## Overview

 This project implements the Mandelbrot set computation in several forms to explore how different parallelization schemes affect correctness, scalability and performance. The codebase is organized by laboratory assignment and contains:

 - Tareador-instrumented sequential implementations (used to identify task candidates).
 - OpenMP loop-based and task-based implementations (iterative and recursive decompositions).
 - Scheduling strategy experiments implemented in C++ (block, cyclic, block-cyclic).

 The goal is both educational (course assignments) and practical: the repository demonstrates the design and evaluation of shared-memory parallel programs.

 ## Objectives & Competencies (Programming II)

 - **Parallel programming**: Demonstrates task decomposition, OpenMP pragmas, and synchronization primitives.
 - **Decomposition strategies**: Iterative (row/column, tiled) vs recursive (quad-tree) approaches.
 - **Scheduling & load balancing**: Compares static block, cyclic, and block-cyclic distributions.
 - **Performance engineering**: Use of instrumentation (Tareador), measurement and benchmarking scripts.
 - **Modularity & code organization**: Clear separation of variants and reusable helper code.
 - **Build and reproducibility**: Make-based build targets and example scripts for repeatable experiments.

 ## Architecture & Project Structure

 Top-level layout (reorganized):

 ```
 ParallelMandelbrot/
 ├── README.md
 ├── assignment-specs/          # Original assignment PDFs and lab statements
 ├── build/                    # Master Makefile and build targets
 ├── docs/                     # Documentation, implementation notes
 ├── examples/                 # Sample inputs and sample output images
 ├── scripts/                  # Convenience scripts (benchmarks, run-all)
 └── src/
     ├── lab3-sequential-tareador/
     │   ├── iterative/        # Iterative sequential variants with Tareador
     │   └── recursive/        # Recursive decomposition (Tareador-instrumented)
     ├── lab4-openmp-variants/
     │   ├── iterative/        # OpenMP loop-based variants
     │   └── recursive-tasks/  # OpenMP task-based recursive variants
     └── lab5-scheduling-strategies/  # C++ experiments: block/cyclic/block-cyclic
 ```

 Key source files to review:

 - [lab3 sequential (recursive example)](src/lab3-sequential-tareador/recursive/mandel-seq-rec-tar-tree.c)
 - [lab3 sequential (iterative example)](src/lab3-sequential-tareador/iterative/mandel-seq-iter-tar.c)
 - [lab4 OpenMP recursive tasks](src/lab4-openmp-variants/recursive-tasks/mandel-omp-rec-tree.c)
 - [lab4 OpenMP iterative (fine grain)](src/lab4-openmp-variants/iterative/mandel-omp-iter-fine-grain.c)
 - [lab5 scheduling: block variant (C++)](src/lab5-scheduling-strategies/mandel-omp-iter-block.cpp)

 Each variant accepts common runtime parameters (image size, max iterations, display/output options). See `docs/IMPLEMENTATION_GUIDE.md` for full usage and examples.

 ## Technologies & Tools

 - Language: C (C99-style) and C++ for scheduling experiments
 - Compiler: GCC / G++ with OpenMP support (recommended: GCC 9+)
 - Libraries: X11 development headers (`libx11-dev`) for display support, math library (`-lm`)
 - Instrumentation: Tareador (used in Lab 3 to annotate tasks)
 - Build: GNU Make

 ## Requirements & Installation

 Install system dependencies on Debian/Ubuntu:

 ```bash
 sudo apt update
 sudo apt install build-essential libx11-dev git
 ```

 Optional (for Lab 3): install the Tareador analysis library if you intend to run instrumented builds.

 Build the project (master Makefile in `build/`):

 ```bash
 # Build everything
 make -C build all

 # Or build a single lab
 make -C build lab4
 ```

 Example run (OpenMP iterative, headless output):

 ```bash
 # set thread count and run
 OMP_NUM_THREADS=4 ./build/mandel-omp-iter -w 512 -i 200 -o examples/sample-images/mandelbrot-512x512.ppm
 ```

 Notes:
 - If X11/display is not available, use the `-o <file>` option to write PPM output files instead of opening a window.
 - For Lab 3 builds, the Makefile links with `-ltareador`; if Tareador is unavailable, build will fail—see `docs/IMPLEMENTATION_GUIDE.md` for a fallback.

 ## Main Features

 - Multiple algorithmic variants: iterative and recursive Mandelbrot kernels.
 - Tareador annotations for task analysis (lab 3).
 - OpenMP loop-based and task-based parallel implementations (lab 4).
 - Scheduling experiments comparing block, cyclic, and block-cyclic strategies (lab 5, C++).
 - Reproducible Makefile-driven builds and example scripts to benchmark scalability.

