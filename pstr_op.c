#include "monty.h"
/**
 * printString - prints the string starting at the top of the stack,
 * followed by a new
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void printString(stack_t **top, unsigned int line)
{
	stack_t *current;
	(void)line;

	current = *top;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
