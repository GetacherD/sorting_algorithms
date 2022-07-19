#include "sort.h"
/**
 * merge - merges two array sorting them
 * @left: left array
 * @right: right array
 * @size_L: size of left array
 * @size_R: size of right array
 * @array: array to be sorted
 */
void merge(int *left, int *right, size_t size_L, size_t size_R, int *array)
{
	size_t i = 0, j = 0, k = 0, ip, jp;

	printf("Merging...\n[left]: ");
	for (ip = 0; ip < size_L - 1; ip++)
		printf("%d, ", left[ip]);
	printf("%d\n", left[size_L - 1]);
	printf("[right]: ");
	for (jp = 0; jp < size_R - 1; jp++)
		printf("%d, ", right[jp]);
	printf("%d\n", right[size_R - 1]);
	while (i < size_L && j < size_R)
	{
		if (left[i] < right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < size_L)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < size_R)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	for (i = 0; i < k - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[k - 1]);
}
/**
 * merge_sort - sort array using merge algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, j = 0, size_L, size_R;
	int *left, *right;

	if (size <= 1)
		return;
	size_L = size / 2;
	size_R = size - size_L;
	left = malloc(sizeof(int) * size_L);
	right = malloc(sizeof(int) * size_R);
	for (i = 0; i < size; i++)
	{
		if (i < size_L)
			left[i] = array[i];
		else
		{
			right[j] = array[i];
			j++;
		}
	}
	merge_sort(left, size_L);
	merge_sort(right, size_R);
	merge(left, right, size_L, size_R, array);
	free(left);
	free(right);
}
