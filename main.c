#include "monty.h"

/**
 * main - reads monty byte codes
 * @argc: counts args in command line
 * @argv: pointer to pointer of arguments in command line
 * Return: EXIT_SUCCESS on yay or EXIT_FAILURE on nay
 */

int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t read;
	size_t len = 0;
	char *line = NULL, *opcode;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &len, file);
	while (read != -1)
	{
		opcode = strtok(line, " \t\r\n'$'");
		if (opcode == NULL)
		{
			line_number = line_number + 1;
		read = getline(&line, &len, file);
			continue;
		}
		find_cmd(opcode, &stack, line_number);
		read = getline(&line, &len, file);
		line_number = line_number + 1;

	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
