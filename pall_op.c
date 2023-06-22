#include "monty.h"
/**
 * pall_op - Prints the elements of the stack
 * @top: Pointer to the stack
 * @line: Line number in the script (unused)
*/
void pall_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse stack */
	(void)line; /* Silence compiler warning about an unused variable 'line' */

	current = *top; /* Set 'current' to point to the top of stack */
	if (current == NULL)
		return; /* If stack is empty, return without performing further actions */
	while (current)
	{
		printf("%d\n", current->n); /* Print value of current node in stack */
		current = current->next; /* move 'current' to the next node in the stack */
	}
}
