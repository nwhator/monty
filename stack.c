#include "monty.h"
/**
 * stackTop - Prints the top element of the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void stackTop(stack_t **top, unsigned int line)
{
	/* line is used to suppress "unused variable" warning for 'top' parameter */
	(void)top;
	/* line is used to suppress  "unused variable" warning for 'line' parameter */
	(void)line;
	/* Set 'lifi' field of 'interpret' struct to 0 */
	interpret.lifi = 0;
}
