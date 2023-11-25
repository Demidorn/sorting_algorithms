#include "sort.h"

/**
 * selection_sort - sorts array of integers one by one
 * in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Return: ordered list from selection sort
 */

void selection_sort(int *array, size_t size)
{
	size_t index = 0, i = 0, j = 0;
	int min = array[0], val, new_val = 0;

	if (!array || size < 2)
		return;

	while (index < size)
	{
		val = array[index];
		min = array[index];

		for (i = (index + 1); i < size; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				j = i;
				new_val = 1;
			}
		}
		if (new_val)
		{
			array[j] = val;
			array[index] = min;
			print_array(array, size);
		}
		index += 1;
		new_val = 0;
	}
}
