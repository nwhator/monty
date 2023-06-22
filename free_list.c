#include "monty.h"
/**
* free_list - Frees a doubly linked list
* @top: Pointer of head of the list
*/
void free_list(stack_t *top)
{
	stack_t *sum;

	sum = top;
	while (top)
	{
		sum = top->next;
		free(top);
		top = sum;
	}
}
