#include "holberton.h"

/**
 * _path - function that prints environment PATH
 * @env: environment
 * Return: 0 if successful
 */
int _path(char *first, char **input, char **env)
{
	int token_len, first_len;
	char *temp, *left, *right, *token;
	char *new = NULL;

	left = strtok(env, "=");
	temp = strtok(NULL, "=");

	if (_strcmp(left, "PATH") == 0)
	{
		right = strtok(temp, ":");
		while (right)
		{
			token = right;
			token_len = _strlen(token);
			first_len = _strlen(first);

			new = malloc((token_len + first_len + 2) *sizeof(char));
			if (new == NULL)
				return;
			_strcat(new, right);
			_strcat(new, "/");
			_strcat(new, first);
			_strcat(new, "\0");
			if (access(new, X_OK) == 0)
			{
				if (fork() == 0)
					execve(new, input, NULL);
				else
					wait(NULL);
				free(new);
				return (0);
			}
			right = strtok(NULL, ":");
			free(new);
		}
	}

}
