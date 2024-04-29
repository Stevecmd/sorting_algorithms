#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Protoypes */
/* 0. Bubble sort */
void bubble_sort(int *array, size_t size);
void print_array(int *array, size_t size);

/* 1. Insertion sort */
void print_list(const listint_t *list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void insertion_sort_list(listint_t **list);

/* 2. Selection sort  */
void swap_ints(int *a, int *b);
void selection_sort(int *array, size_t size);

/* 3. Quick sort  */
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort(int *array, size_t size);


/* 4. Shell sort - Knuth Sequence  */
void shell_sort(int *array, size_t size);

/* 5. Cocktail shaker sort  */
void cocktail_sort_list(listint_t **list);

/* 6. Counting sort */
void counting_sort(int *array, size_t size);

/* 7. Merge sort */
void merge_sort(int *array, size_t size);

/* 8. Heap sort */
void heap_sort(int *array, size_t size);

/* 9. Radix sort */
void radix_sort(int *array, size_t size);

/* 10. Bitonic sort */
void bitonic_sort(int *array, size_t size);

/* 11. Quick Sort - Hoare Partition scheme */
void quick_sort_hoare(int *array, size_t size);

/* 12. Dealer */


#endif /* SORT_H */