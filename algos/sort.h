#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);

void radix_sort(int *array, size_t size);
void bucket_sort(int *array, size_t size);

#endif
