#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1. On error, -1 is returned..
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_str - prints string
 * @s: string to be printed
 * Return: void
 */
void print_str(char *s)
{
	int i, bytes, wc;

	for (i = 0; s[i] != '\0'; i++)
		;

	bytes = i;

	wc = write(STDOUT_FILENO, s, bytes);
	if (wc == EOF)
		return;
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


/**
 * parser - function that takes a string from the command line and returns the
 * string as a parsed double pointer using a space as the delimiter
 * @l: Char pointer storing user input
 * Return: Char double pointer comprised of a char pointers that each contain
 * an argument
 */

char **parser(char *l)
{
	char **args;

	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;

	int arg_num = 0, i = 0;

	linecopy = _strdup(l);
	parsed = strtok(linecopy, " \t");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parsed2 = strtok(l, " \t");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t");
		i++;
	}

	args[i] = NULL;
	free(linecopy);
	return (args);
}


/**
 * special_char - if the user types control d, it exits the shell and handles
 * the error when the user keeps on tabbing, it carries out the command
 * @bytes: the number of bytes read in from the user input
 * @buffer: the buffer
 * @ex_st: the exit status
 * Return: Always (0) for succcess
 */
int  special_char(char *buffer, ssize_t bytes, int *ex_st)
{
	int i = 0;

	if (bytes == EOF && isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(buffer);
		exit(*ex_st);
	}

	if (bytes == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*ex_st);
	}

	if (_strcmp(buffer, "\n") == 0)
	{
		*ex_st = 127;
		return (127);
	}

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	*ex_st = 127;
	return (127);
}
