#include "monty.h"
/**
* free_list - Frees a doubly linked list
* @top: Pointer of head of the list
*/
void free_list(stack_t *top)
{
	stack_t *sum; /* Declare pointer variable 'sum' type 'stack_t' */

	sum = top; /* Assign value of 'top' to 'sum' */
	while (top) /* run following block of code while 'top' is not NULL */
	{
		sum = top->next; /* set 'next' member of 'top' to 'sum' */
		free(top); /* Free memory allocated for 'top' */
		top = sum; /* Assign the value of 'sum' to 'top' */
	}
}
