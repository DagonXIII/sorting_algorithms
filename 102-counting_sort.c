#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count_array, *output_array;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	print_count_array(count_array, max + 1);

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}

/**
 * print_count_array - Prints the count array
 * @count_array: The count array
 * @size: The size of the count array
 */
void print_count_array(int *count_array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", count_array[i]);
	}
	printf("\n");
}
