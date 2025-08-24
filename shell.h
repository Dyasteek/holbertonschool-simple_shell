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
void print_env(void);
char *pathfinder(char *command);
char *_getenv(const char *name);
char *commandfinder(char *command);
char *tokenizer(char *command, char *argv[]);
int exec(char *argv[], int line, char *buffer);
char *pathbuilder(char *current, char *command);
int process_command(char *argv[], int line, char *buffer);
char *commandprep(char *argv[], int line, char **original_cmd);
char *pathchecker(char *current, char *command, char *cpy_path);
int forker(char *argv[], int line, char *buffer, char *full_path, char *original_cmd);
void chilito(char *argv[], int line, char *command, char *buffer, char *command2);

/* environment */
extern char **environ;

/* structs */
/**
 * struct path_node - Node structure for path linked list
 * @str: String containing path
 * @next: Pointer to next node
 */
typedef struct path_node
{
	char *str;
	struct path_node *next;
} path_node_t;

#endif
