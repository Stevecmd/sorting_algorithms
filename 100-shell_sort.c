#include "sort.h"

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
	size_t interval = 1, i, j;
	int temp;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			if (i != size - 1)
				printf(", ");
		}
		printf("\n");

		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		interval = (interval - 1) / 3;
	}

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * shell_sort_main - Main function to test the shell_sort function.
 *
 * Return: Always returns 0.
 */
int shell_sort_main(void)
{
	int array[] = {8, 3, 5, 1, 2, 7, 4, 6};
	size_t size = sizeof(array) / sizeof(array[0]);

	size_t i;

	printf("Original array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");

	shell_sort(array, size);

	return (0);
}
