#include "sort.h"

void merge(int *array, int left, int mid, int right, int *temp);
void merge_sort_recursive(int *array, int left, int right, int *temp);

void merge(int *array, int left, int mid, int right, int *temp)
{
	int i = left, j = mid + 1, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = 0; i < k; i++)
		array[left + i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, k);
}

void merge_sort_recursive(int *array, int left, int right, int *temp)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid, temp);
		merge_sort_recursive(array, mid + 1, right, temp);
		merge(array, left, mid, right, temp);
	}
}

void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	if (temp != NULL && array != NULL && size >= 2)
	{
		printf("\n");
		merge_sort_recursive(array, 0, size - 1, temp);
	}

	if (temp != NULL)
	{
		free(temp);
	}
}
