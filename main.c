#include "monty.h"
bus_t interpret = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: The location of the Monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content; /* Variable to store content of each line read from file */
	FILE *new_file; /* Pointer to file to be opened */
	size_t size = 0; /* set size for getline() function */
	ssize_t read_line = 1; /* Number of characters read by getline() function */
	stack_t *new_stack = NULL; /* Pointer to stack structure */
	unsigned int line = 0; /* Counter to keep track of the line number */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	new_file = fopen(argv[1], "r");
	interpret.file = new_file;
	if (!new_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); /* rid program with a failure status */
	}
	while (read_line > 0)
	{
		content = NULL; /* Reset content pointer for each line read */
		read_line = getline(&content, &size, new_file);
		interpret.content = content;
		line++; /* Increment the line number counter */
		if (read_line > 0)
		{
			executeMonty(content, &new_stack, line, new_file);
		}
		free(content); /* Free memory allocated by getline() for content of line */
	}
	free_list(new_stack); /* Free memory allocated for stack structure */
	fclose(new_file); /* Close the file */
return (0); /* Return 0 to indicate successful program execution */
}
