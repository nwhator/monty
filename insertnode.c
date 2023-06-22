#include "monty.h"

/**
 * insertNode - Insert a node at the beginning of the linked list
 * @top: Pointer to the head of the linked list
 * @n: Value to be stored in the new node
*/

void insertNode(stack_t **top, int n)
{
	stack_t *new, *sum;

	sum = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (sum)
		sum->prev = new;
	new->n = n;
	new->next = *top;
	new->prev = NULL;
	*top = new;
}
