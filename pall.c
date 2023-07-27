#include "monty.h"
/**
 *pall - prints stack
 *@stack: stack given
 *@line_count: count of lines
 *Return: nothing
*/
void pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	_print_stack(*stack);
}
