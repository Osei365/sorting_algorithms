#include "sort.h"

/**
 * swap_func - swaps two listint_t pointers
 * @list: head of the linked list
 * @a: first pointer
 * @b: second pointer
 */
void swap_func(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;
}

/**
 * cocktail_sort_list - sorts using coctail sort algorithm
 * @list: liinked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *forward;
	int isswapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	forward = *list;
	while (1)
	{
		isswapped = 0;
		while (forward->next)
		{
			if (forward->n > forward->next->n)
			{
				swap_func(list, forward, forward->next);
				print_list(*list);
				isswapped = 1;
			}
			else
			{
				forward = forward->next;
			}
		}
		while (forward->prev)
		{
			if (forward->n < forward->prev->n)
			{
				swap_func(list, forward->prev, forward);
				print_list(*list);
				isswapped = 1;
			}
			else
			{
				forward = forward->prev;
			}
		}

		if (isswapped == 0)
			break;
	}
}
