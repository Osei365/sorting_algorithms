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
 * radix_sort - sort based on LSD radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int a, b, c, d, *newarray, temp, min;

	if (array == NULL || size < 2)
		return;
	newarray = malloc(sizeof(int) * size);
	if (newarray == NULL)
		return;
	for (a = 0; a < (int)size; a++)
		newarray[a] = array[a];

	for (a = 1; max / a > 0; a = a * 10)
	{
		for (b = 0; b < (int)size; b++)
		{
			min = newarray[b] % 10;
			d = b;
			for (c = b + 1; c < (int)size; c++)
			{
				if (newarray[c] % 10 < min)
				{
					min = newarray[c] % 10;
					d = c;
				}
			}

			temp = array[d];
			array[d] = array[b];
			array[b] = temp;

			temp = newarray[d];
			newarray[d] = newarray[b];
			newarray[b] = temp;
		}
		for (b = 0; b < (int)size; b++)
			newarray[b] = newarray[b] / 10;
		print_array(array, size);
	}
	free(newarray);
}
