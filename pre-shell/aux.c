#include "shell.h"

/**
 * tokenizer - Tokenize a command string into arguments
 * @command: The command to tokenize
 * @argv: Array to store the arguments
 *
 * Return: Pointer to allocated command copy, or NULL on error
 */
char *tokenizer(char *command, char *argv[])
{
	int i = 0;
	char *token;
	char *command2;

	command2 = malloc(strlen(command) + 1);
	if (command2 == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strcpy(command2, command);
	token = strtok(command2, " \n\t");
	while (token != NULL && i < 1023)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	argv[i] = NULL;
	return (command2);
}

/**
 * chilito - Handle the child process execution
 * @argv: Array of arguments
 * @line: Line number
 * @command: Original command
 * @buffer: Buffer to free
 * @command2: Command copy to free
 *
 * Return: void
 */
void chilito(char *argv[], int line, char *command, char *buffer,
		char *command2)
{
	if (execve(argv[0], argv, environ) == -1)
	{
		printf("shell: %d: %s: not found\n", line, command);
		free(command2);
		free(buffer);
		fflush(stdout);
		_exit(1);
	}
}

void print_env(char *token)
{				
    char *path;

    if (token == NULL)
        return;

    if (strcmp(token, "env") == 0)
    {
        path = _getenv("PATH");
        if (path)
            printf("PATH=%s\n", path);
    }
}