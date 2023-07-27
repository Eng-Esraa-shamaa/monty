#include "monty.h"
/**
*pop - pops from stack
*@stack: stack given
*@line_count: count of line
*Return: nothing
*/
void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack == NULL)
	{
		return;
	}
	(*stack)->prev = NULL;
}
