CC = gcc
CXX = g++
CFLAGS = -O2 -g -Wall
OPENMP = -fopenmp
LIBS = -lX11 -lm
TAREADOR_LIBS = -ltareador

.PHONY: all lab3 lab4 lab5 clean

all: lab3 lab4 lab5

# Lab 3: sequential + Tareador
lab3: build/mandel-seq-iter build/mandel-seq-rec

build/mandel-seq-iter: ../src/lab3-sequential-tareador/iterative/mandel-seq-iter-tar.c
	$(CC) $(CFLAGS) -o $@ $< $(TAREADOR_LIBS) $(LIBS)

build/mandel-seq-rec: ../src/lab3-sequential-tareador/recursive/mandel-seq-rec-tar.c
	$(CC) $(CFLAGS) -o $@ $< $(TAREADOR_LIBS) $(LIBS)

# Lab 4: OpenMP variants (C)
lab4: build/mandel-omp-iter build/mandel-omp-rec

build/mandel-omp-iter: ../src/lab4-openmp-variants/iterative/mandel-omp-iter-fine-grain.c
	$(CC) $(CFLAGS) $(OPENMP) -o $@ $< $(LIBS)

build/mandel-omp-rec: ../src/lab4-openmp-variants/recursive-tasks/mandel-omp-rec-tree.c
	$(CC) $(CFLAGS) $(OPENMP) -o $@ $< $(LIBS)

# Lab 5: Scheduling strategies (C++)
lab5: build/mandel-block build/mandel-cyclic build/mandel-blockcyclic

build/mandel-block: ../src/lab5-scheduling-strategies/mandel-omp-iter-block.cpp
	$(CXX) $(CFLAGS) $(OPENMP) -o $@ $< $(LIBS)

build/mandel-cyclic: ../src/lab5-scheduling-strategies/mandel-omp-iter-cyclic.cpp
	$(CXX) $(CFLAGS) $(OPENMP) -o $@ $< $(LIBS)

build/mandel-blockcyclic: ../src/lab5-scheduling-strategies/mandel-omp-iter-block-cyclic.cpp
	$(CXX) $(CFLAGS) $(OPENMP) -o $@ $< $(LIBS)

clean:
	rm -f build/*
