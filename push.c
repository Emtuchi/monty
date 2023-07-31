#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
	int i;

	if (copy.arg)
	{
		if (copy.arg[0] == '-')
			i++;

		while (copy[i].arg != '\0')
		{
			if (copy.arg[i] < '0' || copy.arg[i] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(bus.file);
				free(bus.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(copy.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
