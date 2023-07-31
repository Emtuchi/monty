#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
typedef struct copy_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} copy_t;
extern copy_t copy;
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
