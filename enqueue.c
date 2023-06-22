#include "monty.h"
/**
 * queue_op - Prints the elements of the queue
 * @top: Pointer to the top of the stack
 * @line: line_number
 * Return: no return
*/
void queue_op(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
	interpret.lifi = 1;
}

/**
 * enqueue - Adds an element to the queue
 * @top: Pointer to the front of the queue
 * @n: Element to be added
 * Return: no return
*/
void enqueue(stack_t **top, int n)
{
	stack_t *new, *sum;

	sum = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (sum)
	{
		while (sum->next)
			sum = sum->next;
	}
	if (!sum)
	{
		*top = new;
		new->prev = NULL;
	}
	else
	{
		sum->next = new;
		new->prev = sum;
	}
}
