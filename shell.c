#include "holberton.h"

/**
 * main - Program that is simple UNIX command interpreter
 * @argc: argument count
 * @argv: argument vector
 * @env: the environment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	(void)argc, (void)**argv;

	char *prompt = "##--->";
	char *line = NULL;
	char **args = NULL;
	int i = 0, status = 0, arg_num = 0;
	size_t len = 0;
	ssize_t read = 0;

	while (read != EOF)
	{
		if (isatty(STDOUT_FILENO) == 1)
			write(STDOUT_FILENO, prompt, 6);

			read = getline(&line, &len, stdin);

			if (special_char(line, read) == 127)
				continue;

			no_nl(line);

			args = parser(line);

			for (i = 0; args[i]; i++)
				arg_num++;

			if (_strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(EXIT_SUCCESS);
			}

			if (_strcmp(args[0], "env") == 0)
				printenv(env);

			status = _path(args[0], args, env);

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
	free(line);
	return (0);
}
