#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using bubble sort
 * @array: the array
 * @size: the size of the array
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t ii;
	int temp;
	int unsorted = 1;

	while (unsorted)
	{
		unsorted = 0;

		for (ii = 1 ; ii < size ; ii++)
		{
			if (array[ii] < array[ii - 1])
			{
				unsorted = 1;

				temp = array[ii];
				array[ii] = array[ii - 1];
				array[ii - 1] = temp;

				print_array(array, size);
			}
		}
	}
}
