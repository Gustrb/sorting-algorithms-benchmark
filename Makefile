CFLAGS = -O3 -Wall -Wextra -Werror -pedantic -std=c99 -lm
LIBS = algos/quick_sort.c algos/merge_sort.c algos/heap_sort.c algos/counting_sort.c algos/radix_sort.c algos/bucket_sort.c

all: bin
	gcc benchmark.c -o ./bin/benchmark $(CFLAGS) $(LIBS)

test: tests/test.c bin
	gcc ./tests/test.c -o ./bin/test $(CFLAGS) $(LIBS)

bin:
	mkdir -p bin
