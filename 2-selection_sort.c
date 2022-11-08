#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order using the
 * Selection sort algorithm.
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t min_i, i, j = 0;
	int min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		min_i = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_i = j;
			}
		}
		if (min != array[i])
		{
			array[min_i] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
