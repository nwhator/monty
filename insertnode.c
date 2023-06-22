#include "monty.h"
/**
 * insertNode - Insert a node at the beginning of the linked list
 * @top: Pointer to the head of the linked list
 * @n: Value to be stored in the new node
*/
void insertNode(stack_t **top, int n)
{
	stack_t *new, *sum; /* set current top of the stack to 'sum' variable */

	sum = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n"); /* Display an error message if memory allocation failed */
		exit(0); /* rid program if memory allocation failed */
	}
	if (sum)
		sum->prev = new;
	new->n = n; /* Set value of new node to given value 'n' */
	new->next = *top; /* next pointer of new node to point,current top stack */
	new->prev = NULL;
	*top = new; /* Update top of stack to point to new node */
}
