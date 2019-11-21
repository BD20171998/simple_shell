#include "holberton.h"

/**
 * cpy_env - creates the copy of the environment variable
 * @env: the environment
 *
 * Return: a character string or 0 for success
 */
char *cpy_env(char **env)
{
	char *env_cpy;
	int i;

	for (i = 0; env[i] != '\0'; i++)
		;

	env_cpy = malloc((i + 1) * sizeof(char));
	if (env_cpy == NULL)
		return (NULL);

	_strcpy(env_cpy, env[i]);

	return (env_cpy);
}
