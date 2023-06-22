#include "monty.h"

/**
 * pchar_op - Prints the char at the top of the stack, followed by a new line
 * @top: Pointer to the Pointer to the top of the stack
 * @line: Line number in the script
*/

void pchar_op(stack_t **top, unsigned int line)
{
	stack_t *current;

	current = *top;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
