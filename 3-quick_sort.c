#include "sort.h"
/**
*quick_sort - Function that sorts an array of integers in ascending order
*using Quick sort algorithm
*
*@array: Pointer to array of integers
*@size: Size of the array
*
*/
void quick_sort(int *array, size_t size)
{


	if (array == NULL || size < 2)
		return;

	quick(array, 0, size - 1, size);
}

/**
*quick - Function that recursively sorts an array of integers by seperating
*them into two partitions using Lomuto quick sort
*
*@array: Pointer to array of integers
*@low: Index at beginning of partition
*@high: Index at end of partition
*@size: Size of the array
*/
void quick(int *array, size_t low, size_t high, size_t size)
{
	size_t index;

	if (low < high)
	{
		index = partition(array, low, high, size);

		if (index != 0)
			quick(array, low, index - 1, size);

		if (index < size - 1)
			quick(array, index + 1, high, size);
	}
}

/**
*partition - Function that scans a partition of an integer array to find values
*less than the pivot value (value at high) and swaps them with the value at the
*beginning of the partition
*
*@array: Pointer to integer array
*@low: Index at the beginning of parition
*@high: Index at end of partition
*@size: Size of array
*
*Return: Index value for next partition
*/
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp;

	i = low;

	for (j = low; j < high; j++)
	{
/*Check if current value is lesser that pivot, array[high] and swap*/
		if (array[j] < array[high])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}
