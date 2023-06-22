#include "monty.h"
/**
 * pint_op - prints the topPrints the top element of the stack
 * @top: Pointer to the stack
 * @line: Line number of the command
*/
void pint_op(stack_t **top, unsigned int line)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(interpret.file); /* Close the file */
		free(interpret.content); /* Free memory allocated for line content */
		free_list(*top); /* Free the memory allocated for the stack */
		exit(EXIT_FAILURE); /* rid program with a failure */
	} /* Print value (integer) stored in top node of stack */
	printf("%d\n", (*top)->n);
}
