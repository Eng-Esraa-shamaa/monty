#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *_add -  adds two nodes of stack
 *@stack: stack given
 *@line_count: count of lines
 *Return: nothing
*/
void _add(stack_t **stack, unsigned int line_count)
{
	int res;

	if ((stack == NULL) || (*stack == NULL) || (((*stack)->next) == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = res;
}
