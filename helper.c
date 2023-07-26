#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 *queue_node - new node to a stack in queue
 *@stack: head of stack
 *@n: numbers of node
 *Return: new node
*/
stack_t *queue_node(stack_t **stack, const int n)
{
stack_t *new_node = malloc(sizeof(stack_t));
stack_t *current_node = *stack;

if (new_node == NULL)
{
free(new_node);
return (NULL);
}
new_node->n = n;
if (*stack == NULL)
{
new_node->next = NULL;
new_node->prev = NULL;
*stack = new_node;
return (new_node);
}
while (current_node != NULL)
{
if (!current_node->next)
{
new_node->next = NULL;
new_node->prev = current_node;
current_node->next = new_node;
break;
}
current_node = current_node->next;
}
return (new_node);
}
