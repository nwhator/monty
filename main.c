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
	char *data;
	new_file *new_file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *new_stack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	new_file = fopen(argv[1], "r");
	interpret.new_file = new_file;
	if (!new_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		data = NULL;
		read_line = getline(&data, &size, new_file);
		interpret.data = data;
		line++;
		if (read_line > 0)
		{
			executeMonty(data, &new_stack, line, new_file);
		}
		free(data);
	}
	free_list(new_stack);
	fclose(new_file);
return (0);
}
