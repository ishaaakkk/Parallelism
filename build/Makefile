CC = gcc
CXX = g++
CFLAGS = -O2 -g -Wall
OPENMP = -fopenmp
LIBS = -lX11 -lm
TAREADOR_LIBS = -ltareador
INCLUDES = -I../src/common
COMMON = ../src/common/mandelbrot-gui.c

.PHONY: all lab3 lab4 lab5 clean

all: lab3 lab4 lab5

# Lab 3: sequential + Tareador

lab3: mandel-seq-iter mandel-seq-rec

mandel-seq-iter: ../src/lab3-sequential-tareador/iterative/mandel-seq-iter-tar.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(COMMON) $(TAREADOR_LIBS) $(LIBS)

mandel-seq-rec: ../src/lab3-sequential-tareador/recursive/mandel-seq-rec-tar.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(COMMON) $(TAREADOR_LIBS) $(LIBS)

# Lab 4: OpenMP variants (C)

lab4: mandel-omp-iter mandel-omp-rec

mandel-omp-iter: ../src/lab4-openmp-variants/iterative/mandel-omp-iter-fine-grain.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPENMP) -o $@ $< $(COMMON) $(LIBS)

mandel-omp-rec: ../src/lab4-openmp-variants/recursive-tasks/mandel-omp-rec-tree.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPENMP) -o $@ $< $(COMMON) $(LIBS)

# Lab 5: Scheduling strategies (C++)

lab5: mandel-block mandel-cyclic mandel-blockcyclic

mandel-block: ../src/lab5-scheduling-strategies/mandel-omp-iter-block.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) $(OPENMP) -o $@ $< $(COMMON) $(LIBS)

mandel-cyclic: ../src/lab5-scheduling-strategies/mandel-omp-iter-cyclic.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) $(OPENMP) -o $@ $< $(COMMON) $(LIBS)

mandel-blockcyclic: ../src/lab5-scheduling-strategies/mandel-omp-iter-block-cyclic.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) $(OPENMP) -o $@ $< $(COMMON) $(LIBS)

clean:
	rm -f mandel* *.o || true
