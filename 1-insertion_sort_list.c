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
 * insertion_sort_list - insertion sort algo
 * @list: linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *ptr;

	ptr = *list;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (ptr->next)
	{
		if (ptr->n > ptr->next->n)
		{
			temp = ptr->next;
			swap_func(list, ptr, temp);
			print_list(*list);
			while (temp->prev && temp->n < temp->prev->n)
			{
				swap_func(list, temp->prev, temp);
				print_list((const listint_t *)*list);
			}
		}
		else
		{
			ptr = ptr->next;
		}
	}
}
