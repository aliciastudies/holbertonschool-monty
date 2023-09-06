#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number of read line
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
	{
		temp = current->n;
		current->n = current->next->n;
		current->next->n = temp;
	}
}
