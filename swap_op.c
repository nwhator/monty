#include "monty.h"
/**
 * swap_op - Swaps the top two elements of the stack.
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void swap_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer used for traversal */
	int len = 0, sum; /* Variable used for counting & temporary storage */

	current = *top; /* Set 'current' to point to top of stack */
	while (current)
	{
		current = current->next;
		len++;
	} /* Traverse stack to count number of nodes */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top; /* Reset 'current' to point to top of stack */
	sum = current->n; /* Store value of top node in 'sum' */
	current->n = current->next->n;
	current->next->n = sum;
}
