#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: A pointer to the second node to swap.
 *
 * Description:
 *   This function swaps the positions of two nodes in a doubly-linked list.
 *   The head of the list is updated if one of the swapped nodes is the head.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (*n1 == NULL || n2 == NULL || *h == NULL)
		return;

	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       uses - insertion sort algorithm.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description:
 *   This function sorts a doubly-linked list of integers in ascending order
 *   using the insertion sort algorithm. After each swap operation, it prints
 *   the list to show the current state.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
