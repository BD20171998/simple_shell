#include "holberton.h"

/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: - Char string to be copied
 * Return: Char pointer to the duplicated string. Return NULL if insufficient
 * memory was available to array or if array is NULL
 */

char *_strdup(char *str)
{
	char *dup;

	int i, l;

	if (str == NULL)
		return (NULL);

	l = 0;

	for (i = 0; str[i] != '\0'; i++)
		l++;

	dup = malloc(sizeof(char) * l + 1);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < l ; i++)
		dup[i] = str[i];

	dup[l] = '\0';

	return (dup);

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
	parsed = strtok(linecopy, " ");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " ");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	parsed2 = strtok(l, " ");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;

	return (args);
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
