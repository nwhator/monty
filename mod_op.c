#include "monty.h"

/**
 * mod_op - Computes the remainder of division for top stack elements
 * top element of the stack by the top element of the stack
 * @top: Pointer to the stack
 * @line: Current line number
*/

void mod_op(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	if (current->num == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->next->num % current->num;
	current->next->num = sum;
	*top = current->next;
	free(current);
}
