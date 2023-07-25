#include "sort.h"
/**
 * merger - merges two sub arrays
 * @array: array in question
 * @left: left index
 * @middle: middle index
 * @right: right index
 */
void merger(int *array, int left, int middle, int right)
{
	int a, b, c, *container;
	int n1 = middle - left, n2 = right - middle;

	container = malloc(sizeof(int) * (n1 + n2));
	if (container == NULL)
		return;
	for (a = 0; a < n1; a++)
		container[a] = array[left + a];
	for (a = 0; a < n2; a++)
		container[a + n1] = array[middle + a];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(container, n1);
	printf("[right]: ");
	print_array(container + n1, n2);
	a = 0;
	b = 0;
	c = left;
	while (a < n1 && b < n2)
	{
		if (container[a] <= container[b + n1])
		{
			array[c] = container[a];
			a++;
		}
		else
		{
			array[c] = container[b + n1];
			b++;
		}
		c++;
	}
	for (; a < n1; a++, c++)
		array[c] = container[a];
	for (; b < n2; b++, c++)
		array[c] = container[b + n1];
	printf("[Done]: ");
	print_array(array + left, right - left);
	free(container);
}

/**
 * merge_rec - divides and conquer and sort
 * @array: array to be sorted
 * @left: left boundary
 * @right: right boundary
 */
void merge_rec(int *array, int left, int right)
{
	int middle;

	if (right - left > 1)
	{
		middle = left + (right - left) / 2;

		merge_rec(array, left, middle);
		merge_rec(array, middle, right);
		merger(array, left, middle, right);
	}
}

/**
 * merge_sort - uses merge sort algorithm to sort
 * @array: array to be sorted
 * @size: size to be sorted
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_rec(array, 0, size);
}
