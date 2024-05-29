#include "sort.h"

void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (size_t i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (size_t i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to array[], so that array[] now
    // contains sorted numbers according to current digit
    for (size_t i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
}

void radix_sort(int *array, size_t size)
{
    // Find the maximum number to know number of digits
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
    }
}
