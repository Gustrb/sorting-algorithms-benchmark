#include "sort.h"

void _quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        _quick_sort_recursive(array, low, i);
        _quick_sort_recursive(array, i + 2, high);
    }
}

void quick_sort(int *array, size_t size)
{
    _quick_sort_recursive(array, 0, size - 1);
}
