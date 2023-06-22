#include "monty.h"
/**
  *sub_op- Subtract two numbers
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void sub_op(stack_t **top, unsigned int line)
{
	stack_t *sum; /* Pointer used for traversal & temporary storage */
	int dif, count;

	sum = *top; /* Set 'sum' to point to top of stack */
	for (count = 0; sum != NULL; count++)
		sum = sum->next; /* Traverse stack to count number of nodes */
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = *top; /* Reset 'sum' to point to top of stack */
	dif = sum->next->n - sum->n;
	sum->next->n = dif; /* Update value of 2nd node to be difference */
	*top = sum->next; /* Update top pointer to point to second node */
	free(sum); /* Free memory of prev top node */
}
