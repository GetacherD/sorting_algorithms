#include "sort.h"
/**
 * selection_sort - sort array using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int min, tmp;
	size_t i, j, J;

	min = array[0];
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] <= min)
			{
				min = array[j];
				J = j;
			}
		}
		tmp = array[i];
		array[i] = min;
		array[J] = tmp;
		min = array[i + 1];
		print_array(array, size);
	}
}
