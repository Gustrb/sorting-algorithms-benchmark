#include "sort.h"

static void _heapify(int *array, size_t size, size_t i, size_t total)
{
    size_t largest = i;
    size_t left = 2 * i;
    size_t right = 2 * i + 1;
    int temp;

    if (left <= size && array[left - 1] > array[largest - 1])
        largest = left;

    if (right <= size && array[right - 1] > array[largest - 1])
        largest = right;

    if (largest != i)
    {
        temp = array[i - 1];
        array[i - 1] = array[largest - 1];
        array[largest - 1] = temp;
        _heapify(array, size, largest, total);
    }
}

void heap_sort(int *array, size_t size)
{
    size_t i;
    int temp;

    for (i = size / 2; i > 0; i--)
        _heapify(array, size, i, size);

    for (i = size; i > 1; i--)
    {
        temp = array[0];
        array[0] = array[i - 1];
        array[i - 1] = temp;
        _heapify(array, i - 1, 1, size);
    }
}
