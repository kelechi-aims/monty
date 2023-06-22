#include "monty.h"

global_v glo;

/**
 * free_glo - frees the memory alloc for global variables
 * Return: Nothing
 */
void free_glo(void)
{
	free_dlistint(glo.head);
	free(glo.buff);
	fclose(glo.fd);
}

/**
 * glo_init - initialisea the global variables
 * @fd: points to the file descriptor
 * Return: void
 */
void glo_init(FILE *fd)
{
	glo.fifo = 1;
        glo.curr = 1;
        glo.args = NULL;
        glo.buff = NULL;
        glo.head = NULL;
        glo.fd = fd;
}

/**
 * file_check -  checks if file exits and can be opened
 * @ac: argument counter
 * @av: argument vector
 * Return: file
 */
FILE *file_check(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - Entry point of the Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int ac, char *av[])
{
	FILE *fd;
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t n = 1024;
	ssize_t lines = 0;
	char *token[2] = {NULL, NULL};

	fd = file_check(ac, av);
	glo_init(fd);
	lines = getline(&glo.buff, &n, fd);
	while (lines != -1)
	{
		token[0] = strtok(glo.buff, " \t\n");
		if (token[0] && token[0][0] != '#')
		{
			f = opcode_funs(token[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%u: ", glo.curr);
				fprintf(stderr, "unknown instruction %s\n", token[0]);
				free_glo();
				exit(EXIT_FAILURE);
			}
			glo.args = strtok(NULL, " \t\n");
			f(&glo.head, glo.curr);
		}
		lines = getline(&glo.buff, &n, fd);
		glo.curr++;
	}
	free_glo();
	return (0);
}
