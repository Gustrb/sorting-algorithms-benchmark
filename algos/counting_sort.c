#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int *count = malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (size_t i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            array[j] = i;
            j++;
            count[i]--;
        }
    }

    free(count);
}
