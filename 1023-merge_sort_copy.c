#include "sort.h"
#include <stdio.h>

/* Merge sort my own code */
#define MAX_LENGTH 100

void merge_sort(int a[], size_t length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main_merge_sort()
{
	int array[MAX_LENGTH] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
	size_t length = 10;
	size_t i;

	merge_sort(array, length);

	for (i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

void merge_sort(int a[], size_t length)
{
	merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);

		merge_sorted_arrays(a, l, m, r);
	}
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_length = m - l + 1;
	int right_length = r - m;

	int temp_left[MAX_LENGTH];
	int temp_right[MAX_LENGTH];

	int i, j, k;

	for (i = 0; i < left_length; i++)
		temp_left[i] = a[l + i];

	for (i = 0; i < right_length; i++)
		temp_right[i] = a[m + i + 1];

	i = 0;
	j = 0;
	k = l;

	while (i < left_length && j < right_length)
	{
		if (temp_left[i] <= temp_right[j])
		{
			a[k] = temp_left[i];
			i++;
		}
		else
		{
			a[k] = temp_right[j];
			j++;
		}
		k++;
	}

	while (i < left_length)
	{
		a[k] = temp_left[i];
		i++;
		k++;
	}

	while (j < right_length)
	{
		a[k] = temp_right[j];
		j++;
		k++;
	}
}