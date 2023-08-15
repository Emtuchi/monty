#include "monty.h"

/**
 * _add - adds the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		start = *stack;

		hold = start->n + start->next->n;

		start->next->n = hold;
		*stack = start->next;
		free(start);
	}
}

/**
 * _nop - doesn’t do anything.
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subs the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		start = (*stack)->next;

		hold = (*stack)->n - start->n;

		free(*stack);
		start->n = hold;
		*stack = start;
	}
}

/**
 * _div - div the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		start = (*stack)->next;

		hold = start->n / (*stack)->n;

		free(*stack);
		start->n = hold;
		*stack = start;
	}
}

/**
 * _mul - mul the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		start = (*stack)->next;

		hold = start->n * (*stack)->n;

		free(*stack);
		start->n = hold;
		*stack = start;
	}
}
