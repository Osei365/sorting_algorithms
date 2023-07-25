#include "sort.h"
/**
 * swap - swaps two array values
 * @a: first array pointer
 * @b: second array pointer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - softs array down the tree
 * @array: array to sift
 * @size: size of array
 * @st: size of tree
 * @root: root element to sift
 */
void sift_down(int *array, int size, int st, int root)
{
	int bigger = root;
	int leftnode = root * 2 + 1;
	int rightnode = root * 2 + 2;

	if (leftnode < st && array[leftnode] > array[bigger])
		bigger = leftnode;
	if (rightnode < st && array[rightnode] > array[bigger])
		bigger = rightnode;
	if (bigger != root)
	{
		swap(&array[root], &array[bigger]);
		print_array(array, size);
		sift_down(array, size, st, bigger);
	}
}

/**
 * heap_sort - sort using sift down heap
 * algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;
	for (a = ((int)size) / 2 - 1; a >= 0; a--)
	{
		sift_down(array, size, size, a);
	}
	for (a = (int)size - 1; a > 0; a--)
	{
		swap(&array[a], &array[0]);
		print_array(array, size);
		sift_down(array, size, a, 0);
	}
}
