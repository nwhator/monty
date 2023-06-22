#include "monty.h"
/**
 * queue_op - Prints the elements of the queue
 * @top: Pointer to the top of the stack
 * @line: line_number
 * Return: no return
*/
void queue_op(stack_t **top, unsigned int line)
{
	(void)top; /* Silence compiler warning of unused variable 'top' */
	(void)line; /* Silence compiler warning of unused variable 'line' */
	interpret.lifi = 1; /* Set 'lifi' member of 'interpret' object to 1 */
}

/**
 * enqueue - Adds an element to the queue
 * @top: Pointer to the front of the queue
 * @n: Element to be added
 * Return: no return
*/
void enqueue(stack_t **top, int n)
{
	stack_t *new, *sum; /* set 2 pointer variables 'new' & 'sum' type 'stack */

	sum = *top; /* set value pointed to by 'top' to 'sum' */
	new = malloc(sizeof(stack_t));
	if (new == NULL) /* Check if memory allocation failed */
	{
		printf("Error\n"); /* Print an error message */
	}
	new->n = n; /* set value 'n' to 'n' member of new node */
	new->next = NULL; /* Set 'next' member of new node to NULL */
	if (sum) /* Check if 'sum' is not NULL */
	{
		while (sum->next) /* refine until last node of current stack */
			sum = sum->next; /* Move 'sum' to next node */
	}
	if (!sum) /* Check if 'sum' is NULL */
	{
		*top = new; /* Set 'new' as 1st node of stack by assign address to 'top' */
		new->prev = NULL; /* Set 'prev' member of new node to NULL */
	}
	else
	{
		sum->next = new; /* Set 'next' member of 'sum' to address of 'new' */
		new->prev = sum; /* Set 'prev' member of 'new' to address of 'sum' */
	}
}
