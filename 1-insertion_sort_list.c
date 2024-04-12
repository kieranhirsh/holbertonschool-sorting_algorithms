#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a list in ascending order using insertion sort
 * @list: the doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *check = *list;
	listint_t *compare, *previous;

	while ((check->next != NULL) && (list != NULL))
	{
		check = check->next;
		compare = check;

		while ((compare->prev != NULL) && (compare->prev->n > compare->n))
		{
			if (compare->n == check->n)
				check = compare->prev;

			previous = compare->prev;

			compare->prev = previous->prev;
			previous->next = compare->next;
			if (previous->prev != NULL)
				previous->prev->next = compare;
			else
				*list = compare;
			if (compare->next != NULL)
				compare->next->prev = previous;
			compare->next = previous;
			previous->prev = compare;

			print_list(*list);
		}
	}
}
