#include "sort.h"


/**
 * sort_pivot-sort the list by finding the pivot number
 * @array:array of list
 * @start:list start from 0
 * @end:list ends with size- 1
 * @size:end of list
 * Return:index of list
 */

void  sort_pivot(int *array, int start, int end, size_t size)
{
	int i, j, temp;

	if (start >= end)
		return;
	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] >  array[end])
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	sort_pivot(array, start, i - 1, size);
	sort_pivot(array, i + 1, end, size);
}
/**
 * quick_sort-write a function that print sort order
 * @array:list of array
 * @size:list size
 */

void quick_sort(int *array, size_t size)
{
	sort_pivot(array, 0, (int)size - 1, size);
}
