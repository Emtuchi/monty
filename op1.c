#include "monty.h"

/**
 * _push - adds an element to the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *count_args;
	int val;
	stack_t *insert, *tail;

	count_args = strtok(NULL, " \n\t\r");
	val = countArg_checkDig(count_args, line_number);

	tail = *stack;
	insert = malloc(sizeof(stack_t));
	if (insert == NULL)
	{ fprintf(stderr, "USAGE: monty file\n");
		free(insert);
		exit(EXIT_FAILURE);
	}

	insert->n = val;
	insert->prev = NULL;
	insert->next = NULL;
	if (choice == STACK)
	{ insert->next = (*stack);
		if (*stack != NULL)
			(*stack)->prev = insert;
		(*stack) = insert;
	}
	else if (choice == QUEUE)
	{
		if (*stack == NULL)
		{ *stack = insert;
			tail = insert;
		}
		else
		{
			while (tail->next != NULL)
				tail = tail->next;
			insert->prev = tail;
			tail->next = insert;
			tail = insert;
		}
	}
}

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *start = (*stack);

	(void)line_number;

	if (start == NULL)
		return;

	while (start != NULL)
	{
		printf("%d\n", start->n);
		start = start->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	start = *stack;

	printf("%d\n", start->n);

}

/**
 * _pop - removes the value at the top of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	start = *stack;

	*stack = (*stack)->next;

	free(start);
}

/**
 * _swap - swaps the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int hold;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	hold = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = hold;
}
