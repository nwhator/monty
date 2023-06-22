#include "monty.h"
/**
  *sub_op- Subtract two numbers
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void sub_op(stack_t **top, unsigned int line)
{
	stack_t *sum;
	int dif, count;

	sum = *top;
	for (count = 0; sum != NULL; count++)
		sum = sum->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = *top;
	dif = sum->next->n - sum->n;
	sum->next->n = dif;
	*top = sum->next;
	free(sum);
}
