#include "monty.h"
/**
 * add_top - adds the top two elements of the stack.
 * @top: Pointer to the stack
 * @line: Line number where the function is called
 *
 * Description: Adds the top two elements of the stack and updates the stack
*/
void add_top(stack_t **top, unsigned int line)
{
	stack_t *current; /* Declare pointer variable 'current' of type 'stack_t' */
	int len = 0, sum; /* Declare and set two integer variables 'len' and 'sum' */

	current = *top; /* Assign value pointed to by 'top' to 'current' */
	while (current)
	{
		current = current->next; /* Move 'current' to following node in stack */
		len++; /* raise 'len' by 1 for each node visited */
	}
	if (len < 2) /* see if length of the stack is less than 2 */
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(interpret.file); /* Close a file tied with the 'interpret' object */
		free(interpret.content); /* Free memory allocated for 'interpret.content' */
		free_list(*top); /* Free memory allocated for entire stack */
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	current = *top; /* Reset 'current' to top of stack */
	sum = current->n + current->next->n;
	current->next->n = sum; /* set sum to 'n' value of next node in stack */
	*top = current->next; /* Update 'top' to point to next node in stack */
	free(current); /* Free memory allocated for prev top node */
}
