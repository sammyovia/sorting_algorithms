#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: Address of head node of the linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *end, *a, *b;

	if (!list || !*list)
		return;

	for (end = (*list)->next; end;)
	{
		a = end->prev;
		b = end;
		end = end->next;
		while (a && a->n > b->n)
		{
			if (a->prev == NULL)
				*list = b;
			else
				a->prev->next = b;
			if (b->next)
				b->next->prev = a;
			b->prev = a->prev;
			a->next = b->next;
			a->prev = b;
			b->next = a;
			print_list(*list);
			a = b->prev;
		}
	}
}
