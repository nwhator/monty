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
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
