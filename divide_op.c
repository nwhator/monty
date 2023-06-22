#include "monty.h"

/**
 * divide_top_two - Computes the quotient of the top two stack elements.
 * @top: Pointer to the stack
 * @line: Line number where the division operation is performed.
*/

void divide_top_two(stack_t **top, unsigned int line)
{
	stack_t *current; /* Declare pointer variable 'current' of type 'stack_t' */
	int len = 0, sum; /* Declare and set two integer variables 'len' & 'sum' */

	current = *top; /* set value pointed to 'top' to 'current' */
	while (current) /* run following block of code while 'current' is not NULL */
	{
		current = current->next; /* Move 'current' to next node in stack */
		len++; /* raise 'len' by 1 for each node visited */
	}
	if (len < 2) /* see if length of the stack is less than 2 */
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(interpret.file); /* Close file associated with 'interpret' object */
		free(interpret.content); /*Free memory allocated for 'interpret.content' */
		free_list(*top); /* Free memory allocated for entire stack */
		exit(EXIT_FAILURE); /* end program with a failure status */
	}
	current = *top; /* Reset 'current' to the top of the stack */
	if (current->n == 0) /* see if top element of the stack is zero */
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->next->n / current->n;
	current->next->n = sum;
	*top = current->next; /* Update 'top' to point to next node in stack */
	free(current); /* Free memory allocated for prev top node */
}
