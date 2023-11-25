#include "sort.h"

/**
 * partition - separate the array into partitions
 * @array: array pointer to node list
 * @first: start of sublist
 * @end: end of sublist
 * @size: size of array
 *
 * Return: prints array each time it swaps
 */

int partition(int *array, int first, int end, size_t size)
{
	int index = first, i = first;
	int pivot = array[end], temp;

	for (i = first; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			if (index != i)
				print_array(array, size);
			index += 1;
		}
	}
	temp = array[index];
	array[index] = pivot;
	array[end] = temp;
	if (index != end)
		print_array(array, size);
	return (index);
}

/**
 * quick_sort - orders array with quick sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: array each time it swaps
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}

/**
 * sort - sort recursively both sublists
 * @array: aaray
 * @first: start of sublist
 * @last: end of sublist
 * @size: array size
 *
 * Return: printed array each time it swaps
 */
void sort(int *array, int first, int last, size_t size)
{
	int index;

	if (first < last)
	{
		index = partition(array, first, last, size);
		sort(array, first, index - 1, size);
		sort(array, index + 1, last, size);
	}
}
