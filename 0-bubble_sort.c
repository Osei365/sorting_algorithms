#include "sort.h"
/**
 * bubble_sort - sorts based on bubble sort algo
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int n, temp;
	size_t a;

	while (1)
	{
		n = 0;
		for (a = 0; a < size; a++)
		{
			if (array[a] > array[a + 1])
			{
				temp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = temp;
				print_array(array, size);
				n++;
			}
		}
		if (n == 0)
			break;
	}
}
