#include "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			/* Swap elements */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (i != j)
				print_array(array, size);
		}
	}

	/* Move pivot element to its correct position */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the quicksort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
