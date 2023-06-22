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
	stack_t *current;
	int len = 0, sum;

	current = *top;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*top = current->next;
	free(current);
}
