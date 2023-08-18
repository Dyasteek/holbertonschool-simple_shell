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

int prompt(char *line);
int _exec(char *cm, char *line);
int _which(char *line);
char *_getenv(char *name);
int lsh_help(void);
int lsh_cd(char *line);
void non_interactive(void);
char **str_tok(char* line, char *delimiter);
int t_size(char *line, char delm);

#endif
