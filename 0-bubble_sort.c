#include "sort.h"
/**
 * bubble_sort - sort array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp;
	size_t stop = size;
	int swapped = 0;

	if (!array || size == 1)
		return;
	while (!swapped)
	{
		swapped = 1;
		for (i = 0; i < stop; i++)
		{
			if ((i <= size - 2) && array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 0;
				print_array(array, size);
			}
		}
		stop--;
	}
}
