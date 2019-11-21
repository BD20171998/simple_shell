#include "holberton.h"
#include <sys/wait.h>

/**
 * main - Program that is simple UNIX command interpreter
 * Return: 0
 */
extern char **environ;
int main(int argc __attribute__((unused)),char **argv __attribute__((unused)), char **env) 
{
	char *prompt = "##--->";
	char *line = NULL;

	char **args;
	int arg_num = 0, i, status;
	size_t len = 0;
	ssize_t read;

	while(read != EOF)
	{
			write(STDOUT_FILENO, prompt, 6);
			read = getline(&line, &len, stdin);
			if (read == EOF)
				exit(EXIT_SUCCESS);

			write(STDOUT_FILENO, line, read);

			no_nl(line);

			args = parser(line);

			for (i = 0; args[i]; i++)
				arg_num++;

			if(_strcmp(args[0],"exit") == 0)
				exit(EXIT_SUCCESS);

			status = _path(args[0], args, env);
			printf("%i",status);
	}

	free(line);
	free_grid(args,arg_num);

	return (0);
}
