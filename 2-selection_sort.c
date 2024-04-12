#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using selection sort
 * @array: the array
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t ii, jj, mindex;
	int temp;

	if ((array != NULL) && (size > 1))
	{
		for (ii = 0 ; ii < (size - 1) ; ii++)
		{
			mindex = ii;

			for (jj = (ii + 1) ; jj < size ; jj++)
			{
				if (array[jj] < array[mindex])
					mindex = jj;
			}

			if (mindex != ii)
			{
				temp = array[ii];
				array[ii] = array[mindex];
				array[mindex] = temp;

				print_array(array, size);
			}
		}
	}
}
