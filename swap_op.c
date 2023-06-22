#include "monty.h"

/**
 * swap_op - Swaps the top two elements of the stack.
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void swap_op(stack_t **top, unsigned int line)
{
	stack_t *current;
	int len = 0, sum;

	current = *top;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->n;
	current->n = current->next->n;
	current->next->n = sum;
}
