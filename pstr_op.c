#include "monty.h"
/**
 * printString - prints the string starting at the top of the stack,
 * followed by a new
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void printString(stack_t **top, unsigned int line)
{
	stack_t *current; /* Pointer to traverse stack */
	(void)line; /* Silence compiler warning about an unused variable 'line' */

	current = *top; /* Set 'current' to point to the top of the stack */
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break; /* Break loop if value in current node is out of range */
		}
		printf("%c", current->n);
		current = current->next; /* Move 'current' to next node in stack */
	} /* Print newline character after printing all valid characters from stack */
	printf("\n");
}
