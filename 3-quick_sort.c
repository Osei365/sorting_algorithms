#include "sort.h"
/**
 * swap_func - swap function
 * @a: first pointer
 * @b: second point
 */
void swap_func(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions using lomuto
 * @array: array to be sorted
 * @size: size of array
 * @low: lower boundary
 * @high: higher boundary
 * Return: array
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int j = low, a;
	int pivot = array[high];

	for (a = low; a < high; a++)
	{
		if (array[a] <= pivot)
		{
			if (j < a)
			{
				swap_func(&array[j], &array[a]);
				print_array(array, size);
			}
			j++;
		}
	}
	if (array[j] > pivot)
	{
		swap_func(&array[j], &array[high]);
		print_array(array, size);
	}

	return (j);
}

/**
 * sorter - sorts using lomuto partition
 * @array: array
 * @size: size of array
 * @low: lower boundary
 * @high: higher boundary
 */
void sorter(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, size, low, high);
		sorter(array, size, low, p - 1);
		sorter(array, size, p + 1, high);
	}
}

/**
 * quick_sort - sort using quick sort algo
 * lomuto partition
 * @array: array to be sorted
 * @size: size to be sorted
 */
void quick_sort(int *array, size_t size)
{
	sorter(array, size, 0, size - 1);
}
