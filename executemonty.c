#include "monty.h"
/**
* executeMonty - executes the opcode
* @data: Pointer
* @line: line_counter
* @file: poiner to monty file
* @input: line input
* Return: no return
*/
int executeMonty(char *input, stack_t **data, unsigned int line, FILE *file)
{
	instruction_t operations[] = {
				{"push", push_op}, {"pall", pall_op}, {"pint", pint_op},
				{"pop", pop_op},
				{"swap", swap_op},
				{"add", add_top},
				{"nop", nop_op},
				{"sub", sub_op},
				{"div", divide_top_two},
				{"mul", mul_op},
				{"mod", mod_op},
				{"pchar", pchar_op},
				{"pstr", printString},
				{"rotl", rotate_op},
				{"rotr", rotate_bottom},
				{"queue", queue_op},
				{"stack", stackTop},
				{NULL, NULL}
				};
	unsigned int i = 0; /* Declare & set unsigned integer variable 'i' to 0 */
	char *op; /* Declare character pointer variable 'op' */

	op = strtok(input, " \n\t");
	if (op && op[0] == '#') /* see if 'op' exists & its first character is '#' */
		return (0); /* Return 0 to indicate a comment line */
	interpret.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && op)
	{
		if (strcmp(op, operations[i].opcode) == 0)
		{	operations[i].f(data, line);
			return (0); /* Return 0 to indicate successful execution */
		}
		i++; /* raise 'i' to move to the next operation in the 'operations' array */
	}
	if (op && operations[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(file); /* Close a file associated with the 'file' object 0 */
		free(input); /* free memory allocated for 'input' */
		free_list(*data); /* Free memory allocated for entire data structure */
		exit(EXIT_FAILURE); } /* rid program with a failure status */
	return (1);
}
