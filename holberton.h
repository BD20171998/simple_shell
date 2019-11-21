#ifndef HOLBERTON_H
#define HOLBERTON_H

#define TRUE (1 == 1)
#define FALSE (!TRUE)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

char *_strdup(char *str);

char **parser(char *l);

void no_nl(char *l);

int _strlen(char *s);

int _putchar(char c);

void print_str(char *s);

char *cpy_env(char **env);

char *_strcpy(char *dest, char *src);

void _path(char *first, char **input, char **env);

char *_strcat(char *dest, char *src);

int _strcmp(char *s1, char *s2);

void free_grid(char **grid, int height);

#endif
