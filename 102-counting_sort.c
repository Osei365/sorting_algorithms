#include "sort.h"
/**
 * counting_sort - sort using counting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t max, a;

	if (array == NULL || array < 2)
		return;
	max = array[0];
	for (a = 1; a < size; a++)
	{
		if (array[a] > (int)max)
			max = array[a];
	}

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * (max + 1));
	for (a = 0; a <= max; a++)
		count[a] = 0;

	for (a = 0; a < size; a++)
		count[array[a]]++;

	for (a = 1; a <= max; a++)
		count[a] += count[a - 1];
	for (a = 0; a < size; a++)
		output[--count[array[a]]] = array[a];
	for (a = 0; a < size; a++)
		array[a] = output[a];
	print_array(count, max + 1);
	free(count);
	free(output);
}
