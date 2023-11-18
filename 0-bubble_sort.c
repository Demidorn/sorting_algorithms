#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Return: sorted integers
 */

void bubble_sort(int *array, size_t size)
{
	size_t t;
	int swap, temp;

	if (!array || size < 2)
		return;

	while (swap)
	{
		swap = 0;
		for (t = 0; t < (size - 1) && t != (size - 1); t++)
		{
			if (array[t] > array[t + 1])
			{
				temp = array[t];
				array[t] = array[t + 1];
				array[t + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		t = 0;
	}

}
