#include "sort.h"
/**
 * selection_sort - sort array using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp, ok_swap = 0, stop = 0;
	size_t i, j = 1, J;

	if (!array || size == 1)
		return;
	min = array[0];
	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			stop = 0;
		while (j < size)
		{
			if (array[j] <= min)
			{
				min = array[j];
				J = j;
				ok_swap = 1;
			}
			if (j < size - 1 && array[j] > array[j + 1])
				stop = 0;
			j++;
		}
		if (ok_swap)
		{
			tmp = array[i];
			array[i] = min;
			array[J] = tmp;
			min = array[i + 1];
			if (i != J)
				print_array(array, size);
		}
		else
			min = array[i + 1];
		if (stop == 1)
			break;
		stop = 1;
		ok_swap = 0;
		j = i + 2;
	}
}
