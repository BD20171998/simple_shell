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

#endif
