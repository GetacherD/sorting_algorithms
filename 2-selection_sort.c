#include "sort.h"
/**
 * selection_sort - sort array using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp, ok_swap = 0;
	size_t i, j, J;

	if (!array || size == 1)
		return;
	min = array[0];
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[j] <= min)
			{
				min = array[j];
				J = j;
				ok_swap = 1;
			}
		}
		if (ok_swap)
		{
			tmp = array[i];
			array[i] = min;
			array[J] = tmp;
			min = array[i + 1];
			print_array(array, size);
		}
		ok_swap = 0;
	}
}
