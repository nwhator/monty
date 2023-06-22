#include "monty.h"
/**
 * push_op - add node to the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void push_op(stack_t **top, unsigned int line)
{
	int n, j = 0, custom_flag = 0; /* Variables used for processing argument */

	if (interpret.arg)
	{
		if (interpret.arg[0] == '-') /* see argument starts with a negative sign */
			j++; /* Increment 'j' to skip the negative sign in further processing */
		/*  iterate over characters in argument until end ('\0') is reached */
		for (; interpret.arg[j] != '\0'; j++)
		{
			if (interpret.arg[j] > 57 || interpret.arg[j] < 48)
				custom_flag = 1; /* Set 'custom_flag' to indicate a non-integer value */
		}
		if (custom_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* Free memory allocated for line content */
			free_list(*top); /* Free memory allocated for stack */
			exit(EXIT_FAILURE); /* rid program with a failure status */
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
		insertNode(top, n); /* Insert integer into stack (lifo mode) */
	else
		enqueue(top, n); /* Enqueue the integer into the stack (fifo mode) */
}
