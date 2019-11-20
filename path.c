#include "holberton.h"

/**
 * _path - function that prints environment PATH
 * @env: environment
 * Return: path
 */
char *_path(char *first, char **env)
{
	int i, j, k;
	char *env_cpy;
	char *left, *right, *temp, *tok_len, *new;

	for (i = 0; env[i] != '\0'; i++)
	{
		env_cpy = _strdup(env[i]);

		left = strtok(env_cpy, "=");

		right = strtok(NULL, "=");

		if (_strcmp(left, "PATH") == 0)
	        {
			temp = strtok(right, ":");
			while (temp) /* loops thru right value*/
			{
				tok_len = temp;
				for (j = 0; tok_len[j] != '\0'; j++)  /* loops thru token*/
					;
				for (k = 0; first[k] != '\0'; k++)
					;
				new = malloc((j + k + 2) * sizeof(char)); /* 2: slash & null */
				if (new == NULL)
					return (NULL);
				_strcat(new, first);
				_strcat(new, "/");
				_strcat(new, first);
				_strcat(new, "\0");
				if (access(new, X_OK) == 0)
					return (new);
				temp = strtok(NULL, ":");
				free(new);
			}
		}
	}
	return (NULL);
}
