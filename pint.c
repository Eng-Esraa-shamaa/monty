#include "monty.h"
/**
 *pint - print top info
 *@stack: stack given by main
 *@line_count: count of lines
 *Return: nothing
*/
void pint(stack_t **stack, unsigned int line_count)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
