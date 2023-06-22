#include "monty.h"
/**
 * mod_op - Computes the remainder of division for top stack elements
 * top element of the stack by the top element of the stack
 * @top: Pointer to the stack
 * @line: Current line number
*/
void mod_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse the stack */
	int len = 0, sum;

	current = *top; /* Set 'current' to point to top of stack */
	while (current)
	{
		current = current->next; /* move 'current' to the next node in the stack */
		len++; /* Increment the length counter */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		fclose(interpret.file); /* Close the file */
		free(interpret.content); /* Free memory allocated for line content */
		free_list(*top); /* free memory allocated for stack */
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	current = *top; /* Reset 'current' to point to top of stack */
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->next->n % current->n;
	current->next->n = sum; /* Store result of modulo operation in 2nd element */
	*top = current->next; /* Update top of stack to 2nd element */
	free(current); /* Free memory allocated for prev top element */
}
