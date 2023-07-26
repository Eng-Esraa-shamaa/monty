#include "monty.h"
/**
 *add_node - adds a node to stack
 *@stack: stack
 *@n: number of new node
 *Return: new node
 */
stack_t *add_node(stack_t **stack, const int n)
{
stack_t *new_node;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free(new_node);
return (NULL);
}
new_node->n = n;
new_node->next = *stack;
new_node->prev = NULL;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
return (new_node);
}
