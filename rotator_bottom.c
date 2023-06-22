#include "monty.h"
/**
  *rotate_bottom- Rotates the stack elements towards the bottom
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_bottom(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *duplicate;

	duplicate = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *top;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*top)->prev = duplicate;
	(*top) = duplicate;
}
