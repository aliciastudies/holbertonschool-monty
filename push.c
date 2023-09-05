#include "monty.h"

/**
 * push - pushes a new node onto the top of the stack
 * @stack: pointer to pointer to top of stack
 * @line_number: line number of read line
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer S\n", line_number);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t\r\n'$'");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer T\n", line_number);
		exit(EXIT_FAILURE);
	}
/*	printf("Token: %s\n", token); */
	value = atoi(token);
	if (strspn(token, "0123456789+-") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer \n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
/*	printf("Value: %d\n", value); */
}
