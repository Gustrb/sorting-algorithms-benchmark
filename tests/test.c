#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../algos/sort.h"

static int UNSORTED[] = {3, 2, 1, 5, 4};
static int SORTED[] = {1, 2, 3, 4, 5};

static void _print_array(int *array, size_t size);
static void test_quick_sort(void);
static void test_merge_sort(void);
static void test_heap_sort(void);
static void test_counting_sort(void);
static void test_radix_sort(void);
static void test_bucket_sort(void);

int main(void)
{
    test_quick_sort();
    test_merge_sort();
    test_heap_sort();
    test_counting_sort();
    test_radix_sort();
    test_bucket_sort();

    return EXIT_SUCCESS;
}

static void _print_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


static void test_quick_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    quick_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "quick_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("quick_sort passed\n");
}

static void test_merge_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    merge_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "merge_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("merge_sort passed\n");
}

static void test_heap_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    heap_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "heap_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("heap_sort passed\n");
}

static void test_counting_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    counting_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "counting_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("counting_sort passed\n");
}

static void test_radix_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    radix_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "radix_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("radix_sort passed\n");
}

static void test_bucket_sort(void)
{
    int unsorted[5];
    memcpy(unsorted, UNSORTED, sizeof(UNSORTED));

    bucket_sort(unsorted, 5);

    for (size_t i = 0; i < 5; i++)
    {
        if (unsorted[i] != SORTED[i])
        {
            fprintf(stderr, "bucket_sort failed\n");
            fprintf(stderr, "Expected: ");
            _print_array(SORTED, 5);
            fprintf(stderr, "Got: ");
            _print_array(unsorted, 5);
            exit(EXIT_FAILURE);
        }
    }

    printf("bucket_sort passed\n");
}
