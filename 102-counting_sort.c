#include "sort.h"
/**
 * count_n - count occurance of n in array
 * @array: container array
 * @n: number to be counted
 * @size: size of array
 * Return: number of occurance
 */
int count_n(int n, int *array, size_t size)
{
	size_t i;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] == n)
			count++;
	}
	return (count);
}

/**
 * counting_sort - sort array with counting algorithm
 * @array: array to be sorted
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int i;
	int *index, *value;
	int c;
	int *array_index;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	index = (int *)malloc(sizeof(int) * (max + 1));
	value = (int *)malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		value[i] = i;
	for (i = 0; i <= max; i++)
	{
		c = count_n(value[i], array, size);
		if (c > 0)
			index[i] = c;
		else
			index[i] = 0;
	}
	printf("%d, ", index[0]);
	for (i = 1; i < max; i++)
	{
		index[i] = index[i] + index[i - 1];
		printf("%d, ", index[i]);
	}
	index[max] = index[max] + index[max - 1];
	printf("%d\n", index[max]);
	array_index = (int *)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		array_index[index[value[array[i]] - 1]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = array_index[i];
	free(array_index);
	free(value);
	free(index);
}
