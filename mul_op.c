#include "monty.h"
/**
 * mul_op - Multiplication of the top two elements in the stack.
 * @top: Pointer to the stack
 * @line: Line number in the script
 * Return: no return
*/
void mul_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse stack */
	int len = 0, sum;

	current = *top; /* Set 'current' to point to the top of stack */
	while (current)
	{
		current = current->next; /* Move 'current' to next node in stack */
		len++; /* Increment the length counter */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		fclose(interpret.file); /* Close the file */
		free(interpret.content); /* Free memory allocated for line content */
		free_list(*top); /* Free memory allocated for stack */
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	current = *top; /* Reset 'current' to point to top of stack */
	sum = current->next->n * current->n;
	current->next->n = sum;
	*top = current->next; /* Update top of stack to second element */
	free(current); /* Free memory allocated for previous top element */
}
