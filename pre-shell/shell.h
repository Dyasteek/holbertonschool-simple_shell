#ifndef PROMPT_H
#define PROMPT_H

/* libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* functions */
int exec(char *command, int line, char *buffer);
char *_getenv( const char *name);
char *tokenizer(char *command, char *argv[]);
void chilito(char *argv[], int line, char *command, char *buffer, char *command2);
void print_env(char *token);

/* environment */
extern char **environ;

/* structs */
typedef struct path_node
{
	char *str;
	struct path_node *next;
} path_node_t;

#endif
