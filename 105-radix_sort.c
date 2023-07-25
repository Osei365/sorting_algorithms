#include "sort.h"
/**
 * get_max - gets max in array
 * @array: array in question
 * @size: size of array
 * Return: returns max element
 */
int get_max(int *array, size_t size)
{
	int max = array[0], a;

	for (a = 1; a < (int)size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * countsort - sort using counting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of array
 * @place: place value
 */
void countsort(int *array, size_t size, int place)
{
	int *count, *output, i;
	size_t max, a;

	max = (array[0] / place) % 10;
	for (a = 1; a < size; a++)
	{
		if ((array[a] / place) % 10 > (int)max)
			max = array[a];
	}

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	for (a = 0; a <= max; ++a)
		count[a] = 0;

	for (a = 0; a < size; a++)
		count[(array[a] / place) % 10]++;

	for (a = 1; a < 10; a++)
		count[a] += count[a - 1];
	for (i = size - 1; i >= 0; i--)
		output[--count[(array[i] / place) % 10]] = array[i];
	for (a = 0; a < size; a++)
		array[a] = output[a];
	free(count);
	free(output);
}
/**
 * radix_sort - sort based on LSD radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size), place;

	if (array == NULL || size < 2)
		return;

	for (place = 1; max / place > 0; place *= 10)
	{
		countsort(array, size, place);
		print_array(array, size);
	}
}
