#include "monty.h"

/**
 * pall - prints values of stack starting from top of stack
 * @stack: pointer to pointer to top of stack
 * @line_number: void
 *
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
