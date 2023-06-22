#include "monty.h"

/**
 * f_push - add node to the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/

void f_push(stack_t **top, unsigned int line)
{
	int num, j = 0, custom_flag = 0;

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
	num = atoi(interpret.arg);
	if (interpret.lifi == 0)
		insertNode(top, num);
	else
		enqueue(top, num);
}
