#include "holberton.h"

/**
 * _path - function that prints environment PATH
 * @env: environment
 * Return: path
 */
void _path(char *first, char **input, char **env)
{
	int token_len, first_len;
	char *temp, *left, *right, *token;
	char *environc = NULL, *new = NULL;

	environc = cpy_env(env);

	left = strtok(environc, "=");
	temp = strtok(NULL, "=");

	if (_strcmp(left, "PATH") == 0)
	{
		right = strtok(temp, ":");
		while (right)
		{
			token = right;
			token_len = _strlen(token);
			first_len = _strlen(first);

			new = malloc((token_len + first_len + 2) * sizeof(char));
			if (new == NULL)
				return;
			_strcat(new, right);
			_strcat(new, "/");
			_strcat(new, first);
			_strcat(new, "\0");
			if (access(new, X_OK) == 0) /*Free the copy of env*/
			{
				if (fork() == 0)
					execve(new, input, NULL);
				else
					wait(NULL);
				free(environc);
				free(new);
			}
			right = strtok(NULL, ":");
			free(new);
		}
	}
	exit(1);
}
