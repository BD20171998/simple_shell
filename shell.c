#include "holberton.h"

/**
 * main - Program that is simple UNIX command interpreter
 * Return: 0
 */

int main(void)
{
	char *prompt = "##--->";
	char *line = NULL;

	char **args;

	size_t len = 0;
	ssize_t read;

	while (TRUE)
	{
		write(STDOUT_FILENO, prompt, 6);
		read = getline(&line, &len, stdin);

		write(STDOUT_FILENO, line, read);
		no_nl(line);
		args = parser(line);

		execve(args[0], args, NULL);
	}

	free(line);
	free(args);

	return (0);
}
