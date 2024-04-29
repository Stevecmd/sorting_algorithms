#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = false;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, &start, start->next);
				print_list(*list);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		end = start;
		for (start = end; start != NULL && start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, &start->prev, start);
				print_list(*list);
				swapped = true;
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @h: Pointer to a pointer to the head of the list
 * @n1: Pointer to the first node to swap
 * @n2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (*n1 == NULL || n2 == NULL)
		return;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	if (n2->next != NULL)
		n2->next->prev = *n1;

	(*n1)->next = n2->next;
	n2->prev = (*n1)->prev;
	(*n1)->prev = n2;
	n2->next = *n1;
}
