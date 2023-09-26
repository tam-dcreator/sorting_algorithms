#include "sort.h"
/**
*selection_sort - Function that sorts an integer in ascending order using the
*selection sort algorithm
*
*@array: Pointer to the array of integers
*@size: Size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*Set the initial minimum as i*/
		min = i;
		for (j = i + 1; j < size; j++)
		{
			/**/
			if (array[j] < array[min])
				min = j;
		}
		/**/
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
