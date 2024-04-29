#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 *				using the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array each time the interval decreases.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, current_index, compare_index;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence */
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Iterate over decreasing gaps */
	for (; gap >= 1; gap /= 3)
	{
		/* Perform insertion sort for each gap */
		for (current_index = gap; current_index < size; current_index++)
		{
			/* Perform insertion sort for elements at current_index */
			compare_index = current_index;
			while (compare_index >= gap && array[compare_index - gap] > array[compare_index])
			{
				swap_ints(array + compare_index, array + (compare_index - gap));
				compare_index -= gap;
			}
		}
		/* Print array after each gap reduction */
		print_array(array, size);
	}
}
