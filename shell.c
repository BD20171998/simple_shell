#include "holberton.h"
#include <sys/wait.h>

/**
 * free_grid - function that frees a 2 dimensional grid of int pointers
 * @grid: Char double pointer to be freed
 * @height: int for height of 2D array to be passed
 * Return: void
 */

void free_grid(char **grid, int height)
{

	int k;

	for (k = 0; k < height; k++)
		free(grid[k]);

	free(grid);
}

/**
 * main - Program that is simple UNIX command interpreter
 * Return: 0
 */
extern char **environ;
int main(void)
{
	char *prompt = "##--->";
	char *line = NULL;

	char **args;
	int arg_num = 0, i;
	size_t len = 0;
	ssize_t read;

	do {

			write(STDOUT_FILENO, prompt, 6);
			read = getline(&line, &len, stdin);

			write(STDOUT_FILENO, line, read);
			no_nl(line);
			args = parser(line);

			for (i = 0; args[i]; i++)
				++arg_num;

			if (fork() == 0)
			execve(_path(args[0], environ), args, NULL);
			else
			wait(NULL);


	} while(read != EOF);

	free(line);
	free_grid(args,arg_num);

	return (0);
}
