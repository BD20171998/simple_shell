#include "holberton.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: comparison of two strings
 */
int _strcmp(char *s1, char *s2)
{

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


/**
 * _strlen - gives length of a string
 * @s: string
 * Return: returns length of string
 */
int _strlen(char *s)
{
        int l = 0;

        while (s[l] != '\0')
                l++;

        return (l);
}


int _putchar(char c)
{
        return (write(1, &c, 1));
}


/**
 * _strcpy - copies string to another string
 * @dest: string 1
 * @src: string 2
 * Return: string copy
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; a <= _strlen(src); a++)
		dest[a] = src[a];
	return (dest);
}
