#include "monty.h"

/**
 * main - entry point
 * @argc: number of argument
 * @argv: arguments
 * Description: entry point for stack options and execution
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t pair[] = {
		{"push", _push}, {"queue", _queue},
		{"pall", _pall}, {"stack", _stack},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"mul", _mul}, {"sub", _sub},
		{"div", _div}, {"mod", _mod},
		{"nop", _nop}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	FILE *m;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m = fopen(argv[1], "r");
	if (m == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_parse_exec(m, pair, &stack);

	fclose(m);
	clean_up(&stack);

	return (0);
}

/**
 * clean_up - clean up stack after file is closed
 * @stack: content on stack
 */
void clean_up(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *tmp = *stack;

		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * read_parse_exec - execute fuction
 * @file: file to read from
 * @pair: opcode and function
 * @stack: top of stack
 * Description: reads from giving file, search for function pair in pair[]
 * and executes
 */
void read_parse_exec(FILE *file, instruction_t *pair, stack_t **stack)
{
	char inpt[NUM];
	unsigned int line_number = 1;

	while (fgets(inpt, sizeof(inpt), file))
	{
		char *opcode_tok;
		int size;

		if (inpt[0] == '#')
			continue;

		size = strlen(inpt);
		if (size > 0 && inpt[size - 1] == '\n')
			inpt[size - 1] = '\0';

		opcode_tok = strtok(inpt, " $\n");
		if (opcode_tok != NULL)
		{
			instruction_t *start = pair;

			while (start->opcode != NULL)
			{
				if (strcmp(start->opcode, opcode_tok) == 0)
				{
					start->f(stack, line_number);
					break;
				}
				start++;
			}
			if (start->opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_tok);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
}

/**
 * countArg_checkDig - count argument and checck f it is a digi
 * @count_args: argument
 * Return: int
 */
int countArg_checkDig(char *count_args, unsigned int line_number)
{
	int val, i;

	if (count_args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; count_args[i] != '\0'; i++)
	{
		if (!isdigit(count_args[i]) && count_args[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	val = atoi(count_args);
	return (val);
}
