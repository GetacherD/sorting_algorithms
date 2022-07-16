#include "sort.h"

/**
 * qs - quick sort recursive helper function
 * @array: array to be sorted
 * @size: size of array
 * @left: start index
 * @right: end index
 */
void qs(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1, tmp;
	int j =  left;

	if (left >= right)

		return;
	while (j < right)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	i++;
	tmp = array[i];
	array[i] = pivot;
	array[right] = tmp;
	print_array(array, size);
	qs(array, size, left, i - 1);
	qs(array, size, i + 1, right);
}
/**
 * quick_sort - sort array using quick sort algorith
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 1)
	{
		print_array(array, size);
		return;
	}
	qs(array, size,  0, size - 1);
	print_array(array, size);
}
