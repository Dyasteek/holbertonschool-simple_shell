#ifndef PRE_SHELL_H
#define PRE_SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int prompt(const char *line, int readed);
unsigned int _wcs(char *line);
int _exec(char *cm, char *line);
char **_arrarg(char *line);
int _which(char *line);
char *_getenv(const char *name);
int lsh_exit(char *buf);
int lsh_help(char *buf);
int lsh_cd(char *line);

#endif