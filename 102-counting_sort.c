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
 * copy_data -copy sorted array to origional
 * @array: array to be sorted
 * @size: size of array
 */
void copy_data(int *array, size_t size)
{
	size_t i;
	int c, j;

	for (i = 0; i < size; i++)
	{
		c = array[i];
		if (c > 0)
		{
			j = 1;
			while (array[i - j] == 0 && (((int)i - j) >= 0))
			{
				array[i - j] = array[i];
				j++;
			}
		}
	}
}
/**
 * counting_sort - sort array with counting algorithm
 * @array: array to be sorted
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int *index, *value;
	int c, j;
	int *array_index;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	index = (int *)malloc(sizeof(int) * (max + 1));
	value = (int *)malloc(sizeof(int) * (max + 1));
	for (j = 0; j <= max; j++)
		value[j] = j;
	for (j = 0; j <= max; j++)
	{
		c = count_n(value[j], array, size);
		if (c > 0)
			index[j] = c;
		else
			index[j] = 0;
	}
	printf("%d, ", index[0]);
	for (j = 1; j < max; j++)
	{
		index[j] = index[j] + index[j - 1];
		printf("%d, ", index[j]);
	}
	index[max] = index[max] + index[max - 1];
	printf("%d\n", index[max]);
	array_index = (int *)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		array_index[index[value[array[i]]] - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = array_index[i];
	copy_data(array, size);
	free(array_index);
	free(value);
	free(index);
}
