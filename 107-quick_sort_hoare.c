#include "sort.h"
/**
 * swap - swaps two array pointers
 * @a: first pointer
 * @b: second pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions using hoare
 * @array: array to sort
 * @size: size of array
 * @low: lower bound
 * @high: high
 * Return: returns pivot
 */
int partition(int *array, int size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * hoaresort - sorts using hoare
 * @array: array to be sorted
 * @size: size of array
 * @low: low
 * @high: high
 */
void hoaresort(int *array, int size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);

		hoaresort(array, size, low, pivot - 1);
		hoaresort(array, size, pivot, high);
	}
}

/**
 * quick_sort_hoare - sorts array using hoare partition
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	hoaresort(array, size, 0, size - 1);
}
