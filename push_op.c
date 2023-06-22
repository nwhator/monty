#include "monty.h"

/**
 * push_op - add node to the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/

void push_op(stack_t **top, unsigned int line)
{
	int n, j = 0, custom_flag = 0;

	if (interpret.arg)
	{
		if (interpret.arg[0] == '-')
			j++;
		for (; interpret.arg[j] != '\0'; j++)
		{
			if (interpret.arg[j] > 57 || interpret.arg[j] < 48)
				custom_flag = 1;
		}
		if (custom_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(interpret.file);
			free(interpret.content);
			free_list(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	n = atoi(interpret.arg);
	if (interpret.lifi == 0)
		insertNode(top, n);
	else
		enqueue(top, n);
}
