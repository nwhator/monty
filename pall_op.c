#include "monty.h"

/**
 * pall_op - Prints the elements of the stack
 * @top: Pointer to the stack
 * @line: Line number in the script (unused)
*/

void pall_op(stack_t **top, unsigned int line)
{
	stack_t *current;
	(void)line;

	current = *top;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
