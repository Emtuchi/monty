#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&content, &size, file) != -1)
	{
		counter++;
		if (content != NULL)
		{
			code(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
