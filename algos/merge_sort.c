#include "sort.h"

void _merge_sort_rec(int *array, int *temp, size_t start, size_t end)
{
    if (start >= end)
        return;

    size_t mid = (start + end) / 2;

    _merge_sort_rec(array, temp, start, mid);
    _merge_sort_rec(array, temp, mid + 1, end);

    size_t i = start;
    size_t j = mid + 1;
    size_t k = start;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= end)
        temp[k++] = array[j++];

    for (size_t i = start; i <= end; i++)
        array[i] = temp[i];
}

void merge_sort(int *array, size_t size)
{
    int *temp = malloc(sizeof(int) * size);
    _merge_sort_rec(array, temp, 0, size - 1);
    free(temp);
}
