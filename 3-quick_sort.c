#include <stddef.h>
#include "sort.h"

/**
 * lomuto - finds the partition of an array using the Lomuto partition scheme
 * @array: the array
 * @start: the first element of the array
 * @end: the last element of the array
 * @size: the size of the array
 *
 * Return: the partition point
 */
size_t lomuto(int *array, size_t start, size_t end, size_t size)
{
	size_t ii = start;
	size_t jj;
	int temp;

	for (jj = ii ; jj < end ; jj++)
	{
		if (array[jj] <= array[end])
		{
			if (ii != jj)
			{
				temp = array[ii];
				array[ii] = array[jj];
				array[jj] = temp;
				print_array(array, size);
			}

			ii += 1;
		}
	}

	if (ii != end)
	{
		temp = array[ii];
		array[ii] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (ii);
}

/**
 * quick_sort_recursive - sorts an array in ascending order using quick sort
 * @array: the array
 * @start: the first element of the array
 * @end: the last element of the array
 * @size: the size of the array
 *
 */
void quick_sort_recursive(int *array, size_t start, size_t end, size_t size)
{
	size_t partition;

	if (start < end)
	{
		partition = lomuto(array, start, end, size);
		if (start < partition)
			quick_sort_recursive(array, start, partition - 1, size);
		if (end > partition)
			quick_sort_recursive(array, partition + 1, end, size);
	}
}

/**
 * quick_sort - a wrapper function that calls the function that does tho work
 * @array: the array
 * @size: the size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}

