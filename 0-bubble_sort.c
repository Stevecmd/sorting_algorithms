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
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of the array of integers.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool is_sorted = false;

	if (array == NULL || size < 2)
		return;

	while (!is_sorted)
	{
		is_sorted = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				is_sorted = false;
			}
		}
		len--;
	}
}
