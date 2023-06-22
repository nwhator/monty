#include "monty.h"
/**
 * pchar_op - Prints the char at the top of the stack, followed by a new line
 * @top: Pointer to the Pointer to the top of the stack
 * @line: Line number in the script
*/
void pchar_op(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse stack */

	current = *top; /* Set 'current' to point to top of stack */
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(interpret.file); /* Close the file */
		free(interpret.content); /* free memory allocated for line content */
		free_list(*top); /* Free memory allocated for stack */
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	} /* Print character corresponding to value in top node of stack */
	printf("%c\n", current->n);
}
