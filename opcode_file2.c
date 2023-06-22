#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: points to the stack
 * @line_number: current line number
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value, i;

	if (!glo.args)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	for (i = 0; glo.args[i] != '\0'; i++)
	{
		if (!isdigit(glo.args[i]) && glo.args[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_glo();
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(glo.args);
	if (glo.fifo == 1)
	{
		add_dnodeint(stack, value);
	}
	else
	{
		add_dnodeint_end(stack, value);
	}
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
