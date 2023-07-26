#include "sort.h"
/**
 * swap - compares and swaps
 * @a: first item
 * @b: second item
 * @dir: direction of flow
 */
void swap(int *a, int *b, int dir)
{
	int temp;

	if (dir == (*a > *b))
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * bitonicmerge - merges bitonic sequence
 * @array: array in question
 * @low: lower end
 * @c: center
 * @dir: direction of flow
 */
void bitonicmerge(int *array, int low, int c, int dir)
{
	int k, a;

	if (c > 1)
	{
		k = c / 2;
		for (a = low; a < low + k; a++)
			swap(&array[a], &array[a + k], dir);
		bitonicmerge(array, low, k, dir);
		bitonicmerge(array, low + k, k, dir);
	}
}

/**
 * bitonicseq - bitonic sequence
 * @array: array
 * @size: size of array
 * @low: lower end
 * @c: center
 * @dir: direction of flow
 */
void bitonicseq(int *array, int size, int low, int c, int dir)
{
	int k;
	char *s = (dir == up) ? "UP" : "DOWN";

	if (c > 1)
	{
		printf("Merging [%i/%i] (%s):\n", c, size, s);
		print_array(array + low, c);

		k = c / 2;

		bitonicseq(array, size, low, k, up);
		bitonicseq(array, size, low + k, k, down);
		bitonicmerge(array, low, c, dir);

		printf("Result [%i/%i] (%s):\n", c, size, s);
		print_array(array + low, c);
	}
}

/**
 * bitonic_sort - sort the array using bitonic
 * @array: array to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonicseq(array, size, 0, size, up);
}
