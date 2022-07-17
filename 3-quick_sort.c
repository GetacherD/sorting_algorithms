#include "sort.h"

/**
 * qs - quick sort recursive helper function
 * @array: array to be sorted
 * @size: size of array
 * @left: start index
 * @right: end index
 * @odd: when to print
 */
void qs(int *array, size_t size, int left, int right, int *odd)
{
	int pivot = array[right];
	int i = left - 1, tmp;
	int j =  left;

	if (left >= right)
		return;

	*odd = *odd + 1;
	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	i++;
	if (((*odd) % 2) == 0)
		print_array(array, size);
	tmp = array[right];
	array[right] = array[i];
	array[i] = tmp;
	if (((*odd) % 2) == 1)
		print_array(array, size);
	qs(array, size, left, i - 1, odd);
	qs(array, size, i + 1, right, odd);
}
/**
 * quick_sort - sort array using quick sort algorith
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int k = 0;
	int *odd = &k;

	if (!array || size == 1)
	{
		return;
	}
	qs(array, size,  0, size - 1, odd);
	print_array(array, size);
}
