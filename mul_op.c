#include "monty.h"
/**
 * mul_op - Multiplication of the top two elements in the stack.
 * @top: Pointer to the stack
 * @line: Line number in the script
 * Return: no return
*/
void mul_op(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->next->num * current->num;
	current->next->num = sum;
	*top = current->next;
	free(current);
}
