#include "monty.h"
/**
 * pop_op - Print from the top of the stack
 * @top: Pointer to the stack
 * @line: Line number in the file
*/
void pop_op(stack_t **top, unsigned int line)
{
	stack_t *current;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	*top = current->next;
	free(current);
}
