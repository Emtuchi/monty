#include "monty.h"

Mode choice = STACK;
/**
 * _queue - sets the format of the data to a queue (FIFO).
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	choice = QUEUE;
}
/**
 * _stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: pointer to top stack element
 * @line_number: element count
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	choice = STACK;
}
