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
 * no_nl - removes the new line with the NULL character
 * @l: the line
 * Return: nothing
 */
void no_nl(char *l)
{

	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';
			return;
		}

		i++;
	}
}
