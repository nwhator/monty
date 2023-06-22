#include "monty.h"

/**
 * divide_top_two - Computes the quotient of the top two stack elements.
 * @top: Pointer to the stack
 * @line: Line number where the division operation is performed.
*/

void divide_top_two(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->next->n / current->n;
	current->next->n = sum;
	*top = current->next;
	free(current);
}
