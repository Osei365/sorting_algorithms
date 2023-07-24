#include "sort.h"
/**
 * shell_sort - sorts using shell sort algorithm
 * Knuth's sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, incr = 1;
	int temp;

	if (array = NULL || size < 2)
		return;

	while (incr <= (size - 1)/9)
		incr = (incr * 3) + 1;

	while (incr > 0)
	{
		for (i = incr; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= incr; j = j - incr)
			{
				if (array[j - incr] > temp)
				{
					array[j] = array[j - incr];
				}
				else
					break;
			}
			array[j] = temp;
		}
		incr = incr / 3;
		print_array(array, size);
	}
}
