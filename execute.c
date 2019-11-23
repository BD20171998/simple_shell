#include "holberton.h"

/**
 * _execute - function that executes in the main shell
 * @status: the status of the path, whether the file found is executable or not
 * @line: the buffer
 * @args: the parsed arguments
 * Return: void
 */
void _execute(int status, char *line, char **args)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);
			else
				wait(NULL);
		}

		else
		{
			if (fork() == 0)
			{
				perror(args[0]);
				free(args);
				free(line);
				exit(127);
			}
			else
				wait(NULL);
		}
	}
	free(args);
}
