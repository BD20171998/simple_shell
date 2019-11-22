#include "holberton.h"

/**
 * main - Program that is simple UNIX command interpreter
 * Return: 0
 */
int main(void)
{
	char *prompt = "##--->";
	char *line = NULL;

	char **args = NULL;
	int arg_num = 0, i = 0, status = 0;
	size_t len = 0;
	ssize_t read = 0;

	while(read != EOF)
	{
			write(STDOUT_FILENO, prompt, 6);
			read = getline(&line, &len, stdin);

			if (127 == special_char(line, read))
				continue;

			no_nl(line);

			args = parser(line);

			for (i = 0; args[i]; i++)
				arg_num++;

			if(_strcmp(args[0],"exit") == 0)
			{
				free(args);
				free(line);
				exit(EXIT_SUCCESS);
			}

			if(_strcmp(args[0], "env") == 0)
				printenv(environ);

			status = _path(args[0], args, environ);

			if (status == 2)
			{
				if (access(args[0], X_OK) == 0)
				{
					if (fork() == 0)
						execve(args[0], args, NULL);

					else
						wait (NULL);
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
						wait (NULL);
				}
			}
			free(args);
	}
	free(line);
	return (0);
}
