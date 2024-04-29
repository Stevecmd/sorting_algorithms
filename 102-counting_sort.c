#include "sort.h"

int find_max(int *array, size_t size);
int *allocate_count_array(int max);
void populate_count_array(int *count, int *array, size_t size, int max);
void print_counting_array(int *count, int max);
void build_sorted_array(int *array, int *sorted, int *count, size_t size);

void counting_sort(int *array, size_t size)
{
	int max;
	int *count;
	int *sorted;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);
	count = allocate_count_array(max);
	if (count == NULL)
		return;

	populate_count_array(count, array, size, max);
	print_counting_array(count, max);

	sorted = (int *)malloc(size * sizeof(int));
	if (sorted == NULL) {
		free(count);
		return;
	}

	build_sorted_array(array, sorted, count, size);

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

int *allocate_count_array(int max)
{
	int *count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}
	return count;
}

void populate_count_array(int *count, int *array, size_t size, int max)
{
	size_t i;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;
}

void print_counting_array(int *count, int max)
{
	int i;
	for (i = 0; i <= max; i++)
		printf(" %d", count[i]);
	printf("\n");
}

void build_sorted_array(int *array, int *sorted, int *count, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
}
