#include "monty.h"

/**
 * _mod - mod the top 2 values of the stack
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	int hold;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

		hold = start->n % (*stack)->n;

		free(*stack);
		start->n = hold;
		*stack = start;
	}
}

/**
 * _pchar - prints the char at the top of the stack in the ascii value
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int start;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	start = (*stack)->n;

	if (!isascii(start))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", start);
}

/**
 * _pstr - prints the string starting at d top of the stack in the ascii value
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int val;
	stack_t *start;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	start = *stack;

	while (start != NULL && val != 0)
	{
		val = start->n;
		if (isascii(val))
			printf("%c", val);
		start = start->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top.
 * @stack: pointer to top stack element
 * @line_number: element count
 * Description: top element of the stack becomes the last one, and the second
 * top element of the stack becomes the first one
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *start = *stack;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (start->next != NULL)
		start = start->next;

	*stack = (*stack)->next;
	(*stack)->prev = tmp->prev;

	tmp->next = start->next;
	tmp->prev = start;
	start->next = tmp;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to top stack element
 * @line_number: element count
 * Description: The last element of the stack becomes d top element of d stack
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *back;
	stack_t *start = *stack;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (start->next != NULL)
		start = start->next;

	back = start->prev;
	back->next = start->next;

	start->next = *stack;
	start->prev = (*stack)->prev;

	(*stack)->prev = start;
	*stack = start;
}
