#include "holberton.h"
#include <sys/wait.h>

/**
 * main - Program that is simple UNIX command interpreter
 * Return: 0
 */
int main(int argc __attribute__((unused)),char **argv __attribute__((unused)), char **env) 
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
			if (read == EOF)
				exit(EXIT_SUCCESS);

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
				printenv(env);

			status = _path(args[0], args, env);
			if (status == 2)
			{
				if (access(args[0], X_OK) == 0)
					execve(args[0], args, NULL);
				else
					wait (NULL);
			}
			free(args);
	}
	free(line);
	return (0);
}
