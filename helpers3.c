#include "holberton.h"

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
 * special_char - if the user types control d, it exits the shell and handles
 * the error when the user keeps on tabbing, it carries out the command
 * @bytes: the number of bytes read in from the user input
 * @buffer: the buffer
 * Return: Always (0) for succcess
 */
int  special_char(char *buffer, ssize_t bytes)
{
	int i = 0;

	if (bytes == EOF)
	{
		_putchar('\n');
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (0 == _strcmp(buffer,"\n"))
		return (127);

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	return (127);
}

/**
 * pathstr - function that prints the path string
 * @right: string after "PATH ="
 * @first: first tokenized word
 * Return: 0 for success
 */
char *pathstr(char *right, char *first)
{
	char *new = NULL;
	char *token = NULL;
	int token_len = 0, first_len = 0;

	token = right;
	token_len = _strlen(token);
	first_len = _strlen(first);

	new = malloc((token_len + first_len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);

	new[0] = '\0';

	_strcat(new, right);
	_strcat(new, "/");
	_strcat(new, first);
	_strcat(new, "\0");

	return (new);
}
