#include "monty.h"
/**
 *swap -  swap data
 *@stack: stack given
 *@line_count: count of lines
 *Return: nothing
*/
void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if ((stack == NULL) || (*stack == NULL) || (((*stack)->next) == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp_n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
