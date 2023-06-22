#include "monty.h"
/**
  *rotate_op- This is to rotate the stack to the top
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_op(stack_t **top,  __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *top, *sum; /* Pointers used for temporary storage,swapping */

	if (*top == NULL || (*top)->next == NULL)
	{
		return; /* stack is empty or contains only one element */
		/* no need to perform the swap */
	}
	sum = (*top)->next; /* Store second node of stack in 'sum' */
	sum->prev = NULL; /* Set 'prev' pointer of 'sum' to NULL */
	while (temp->next != NULL)
	{
		temp = temp->next; /* Traverse to last node of stack using 'temp' */
	}
	temp->next = *top;
	(*top)->next = NULL; /* Set 'next' pointer of new top node to NULL */
	(*top)->prev = temp; /* Set 'prev' pointer of new top node to 'temp' */
	(*top) = sum; /* Update top pointer to point to new top node */
}
