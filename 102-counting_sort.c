#include "sort.h"
#include <stdlib.h>

/**
 * max - Return the largest integer in an 'array'
 * @array: array
 * @size: size of array
 * Return: largest integer in 'array'
 */
int max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order using the
 * Counting sort algorithm.
 *
 * Array is assumed to contain only positive integers
 * @array: array
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, count_range;
	int *sorted, *count;

	/* Nothing to do if array is NULL or size < 2 */
	if (!array || size < 2)
		return;
	/* Find largest integer in array */
	count_range = max(array, size) + 1;
	if (count_range < 2)
		return;
	/* Create count array */
	count = calloc(count_range, sizeof(int));
	if (!count)
		return;
	/* Histogram */
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/* Cumulative sum */
	for (i = 0; (i + 1) < count_range; i++)
		count[i + 1] += count[i];
	print_array(count, count_range);
	/* Create sorted array */
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return;
	/* Copy each element of 'array' into 'sorted' */
	/* 'count' returns the index to place array[i] in 'sorted' */
	for (i = 0; i < size; i++)
	{
		/* Indicies in 'count' begin at 1, not 0, so subtract 1 */
		sorted[count[array[i]] - 1] = array[i];
		/* Once an index in count is used, decrement the value */
		count[array[i]]--;
	}
	/* Copy sorted array into original array */
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	/* Free the malloc'd arrays */
	free(sorted);
	free(count);
}
