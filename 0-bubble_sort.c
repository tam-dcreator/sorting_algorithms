#include "sort.h"
/**
* bubble_sort - Function that sorts an array of integers in ascending order
*using Bubble Sort algorithm
*
*@array: Pointer to the array
*@size: Size of the array
*
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	bool flag;

	do {
		flag = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = true;

				print_array(array, size);
			}
		}
	} while (flag);
}
