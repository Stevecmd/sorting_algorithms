#include "sort.h"

/**
 * find_max - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description:
 * Iterates through the array to find the maximum value.
 * Initializes 'max' to the first element and compares it
 * with each subsequent element in the array.
 * If an element greater than 'max' is found, 'max' is updated.
 * Finally, the maximum integer in the array is returned.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *arr, int size)
{
	int max_val, i;

	for (max_val = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > max_val)
			max_val = arr[i];
	}

	return (max_val);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description:
 * This function sorts the given array of integers in ascending order using the
 * counting sort algorithm. It first checks if the array is NULL or if its size
 * is less than 2, in which case it returns immediately. It then dynamically
 * allocates memory for the 'sorted' array and checks for allocation failure.
 * Next, it calculates the maximum value in the array
 * using the find_max function and allocates memory for
 * the counting array 'count'. If the allocation fails,
 * it frees the memory allocated for 'sorted' and returns.
 * The function initializes
 * the counting array to store the frequencies of each
 * element in the array, then computes the cumulative frequencies.
 * It prints the counting array and proceeds
 * to rearrange the elements in the 'sorted' array based on the counting array.
 * Finally, it updates the original array with the sorted elements, frees the
 * allocated memory for 'sorted' and 'count', and returns.
 */
void counting_sort(int *arr, size_t size)
{
	int *count, *sorted, max_val, i;

	if (arr == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_val = find_max(arr, size);
	count = malloc(sizeof(int) * (max_val + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max_val + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[arr[i]] += 1;
	for (i = 0; i < (max_val + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_val + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		arr[i] = sorted[i];

	free(sorted);
	free(count);
}
