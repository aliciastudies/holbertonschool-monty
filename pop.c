#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: void
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
