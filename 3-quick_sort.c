#include "sort.h"

/**
 * quick_sort - Sort an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t L, R, P = size - 1;
	int temp;
	static int *a, S = -1;

	if (!array || size < 2)
		return;
	if (S == -1)
	{
		a = array;
		S = size;
	}
	while (1)
	{
		for (L = 0; array[L] < array[P]; L++)
			continue;
		for (R = P - 1; array[R] > array[P] && R > 0; R--)
			continue;
		if (L < R)
		{
			temp = array[L];
			array[L] = array[R];
			array[R] = temp;
			print_array(a, S);
		}
		else
			break;
	}
	if (L != P)
	{
		temp = array[L];
		array[L] = array[P];
		array[P] = temp;
		print_array(a, S);
	}
	quick_sort(array + L + 1, size - (L + 1));
	quick_sort(array, L);
}
