#include "monty.h"
/**
  *rotate_bottom- Rotates the stack elements towards the bottom
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_bottom(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *duplicate; /* Pointer used for duplicate node traversal */

	duplicate = *top; /* Set 'duplicate' to point to top of stack */
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *top;
	duplicate->prev->next = NULL; /* Set 'next' pointer of prev node to NULL */
	duplicate->prev = NULL; /* Set 'prev' pointer of duplicate node to NULL */
	(*top)->prev = duplicate;
	(*top) = duplicate; /* Update top pointer to point to duplicate node */
}
