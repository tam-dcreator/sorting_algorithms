#include "sort.h"
/**
*insertion_sort_list - Function that sorts a doubly linked list of integers in
*ascending order using Insertion sort algorithm
*
*@list: Pointer to a doubly linked list
*
*Description - The objective is to move the nodes with the lesser value to the
*beginning of the list by continuosly performing a backword swap of the current
*value as long as it is lesser than the values before it
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_a, *swap_b, *temp;

	if (list == NULL)
		return;
	temp = (*list)->next;
	while (temp)
	{
		/*Swap_a manages the current value to be swapped*/
		swap_a = temp;
		temp = temp->next; /*move forward incase current is swapped*/
		/*Swap_b is the value before the current swap value*/
		swap_b = swap_a->prev;

		while (swap_b && swap_a->n < swap_b->n)
/*Moving backwards till we encounter NULL or a value less than current value*/
		{
			if (swap_a->next) /*Not end of the list*/
				swap_a->next->prev = swap_b;
			if (swap_b->prev) /*Not at beginning of the list*/
				swap_b->prev->next = swap_a;
			swap_b->next = swap_a->next;
			swap_a->prev = swap_b->prev;
			swap_a->next = swap_b;
			swap_b->prev = swap_a;
/*After nodes are swapped, set swap_b to the previous value of swap_a, since*/
			/*swap_a has moved a step back*/
			swap_b = swap_a->prev;

/*If at beginning of the list set head to the current value*/
			if (!swap_b)
				*list = swap_a;
			print_list(*list);
		}
	}
}
