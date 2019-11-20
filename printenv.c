#include "holberton.h"

/**
 * printenv - prints the environment variable
 * @env: the environment variable to print
 * Return: Always (0) for sucess
 */
int printenv(char **env)
{
	unsigned int i = 0;
	char *buffer;

	while (env[i] != NULL)
	{
		_printf(env[i]);
			_putchar(\n);
	}

	return (0);
}

/**
 * _printf - print a character
 * @str: the string
 */
void_printf(char *str)
{
	int i = 0;

	for (; str[i]; i++)
	{
		_putchar(str[i]);
	}

}
