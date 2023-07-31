#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/

int code(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ctrl[] = {};
	char *op;
	unsigned int i = 0;

	op = strtok(content, " \n\t");
	copy.arg = strtok(NULL, " \n\t");
	if (op && op[0] == '#')
		return (0);

	while (op && ctrl[i].opcode)
	{
		if (strcmp(op, ctrl[i].opcode) == 0)
		{
			ctrl[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && ctrl[i].opcode == NULL)
	{fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
