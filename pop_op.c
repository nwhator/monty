#include "monty.h"
/**
 * pop_op - Print from the top of the stack
 * @top: Pointer to the stack
 * @line: Line number in the file
*/
void pop_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse the stack */

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(interpret.file); /* Close the file */
		free(interpret.content); /* Free memory allocated for line content */
		free_list(*top); /* Free memory allocated for stack */
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	current = *top; /* Set 'current' to point to top of stack */
	*top = current->next; /* Update top of stack to next node */
	free(current); /* Free memory allocated for prev top node */
}
