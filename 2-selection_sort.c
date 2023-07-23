#include "sort.h"
/**
 * selection_sort - sorts using slection algo
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int searcher, temp;
	size_t a, i, i_to_change;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		searcher = array[a];
		for (i = a + 1; i < size; i++)
		{
			if (searcher > array[i])
			{
				i_to_change = i;
				searcher = array[i];
			}
		}
		if (searcher != array[a])
		{
			temp = array[a];
			array[a] = array[i_to_change];
			array[i_to_change] = temp;
			print_array(array, size);
		}
	}
}
