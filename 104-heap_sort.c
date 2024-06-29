#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Perform the sift-down operation to maintain heap property.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @index: The index of the element to perform sift-down operation.
 * @heap_size: The size of the heap.
 */
void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap_ints(&array[index], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap operation.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i != 0; i--)
	{
		sift_down(array, size, i, size);
	}

	/* Perform heap sort */
	for (i = size - 1; i != 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
