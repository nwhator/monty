#include "monty.h"
/**
  *rotate_op- This is to rotate the stack to the top
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_op(stack_t **top,  __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *top, *sum;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	sum = (*top)->next;
	sum->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = temp;
	(*top) = sum;
}
