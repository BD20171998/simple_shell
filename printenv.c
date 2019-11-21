#include "holberton.h"

/**
 * printenv - prints the environment variable
 * @env: the environment variable to print
 * Return: Always (0) for sucess
 */
int printenv(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		print_str(env[i]);
		_putchar('\n');
		i++;
	}

	return (0);
}
