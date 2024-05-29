#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "algos/sort.h"

typedef void (*sort_func_t)(int *, size_t);

void randomize_array(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % 1000) + 1;
    }
}

void run_benchmark(sort_func_t func, const char *label, size_t size)
{
    const size_t SAMPLES = 20;

    int *arr = malloc(size * sizeof(int));
    randomize_array(arr, size);

    int **arrs = malloc(SAMPLES * sizeof(int *));
    for (size_t i = 0; i < SAMPLES; i++)
    {
        arrs[i] = malloc(size * sizeof(int));
        memcpy(arrs[i], arr, size * sizeof(int));
    }

   clock_t start = clock();
    for (size_t i = 0; i < SAMPLES; i++)
    {
        func(arrs[i], size);
    }

    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC / SAMPLES;

    printf("The algorithm %s using %zu entries took: %f seconds\n", label, size, elapsed);

    for (size_t i = 0; i < SAMPLES; i++)
    {
        free(arrs[i]);
    }

    free(arrs);
}

int main(void)
{
    size_t sizes[] = {10, 100, 1000, 10000, 50000};
    const char *labels[6] = {"Quick Sort", "Merge Sort", "Heap Sort", "Counting Sort", "Radix Sort", "Bucket Sort"};
    sort_func_t funcs[6] = {quick_sort, merge_sort, heap_sort, counting_sort, radix_sort, bucket_sort};

    // For each algorithm, use the sizes array to run the benchmark
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            run_benchmark(funcs[i], labels[i], sizes[j]);
        }
    }

    return EXIT_SUCCESS;
}
