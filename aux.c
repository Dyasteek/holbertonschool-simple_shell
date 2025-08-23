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
		printf("maicol: %d: %s: not found\n", line, command);
		fflush(stdout);
		free(command2);
		free(buffer);
		_exit(1);
	}
}

/**
 * print_env - Print the PATH environment variable
 *
 * Return: void
 */
void print_env(void)
{
	char *path = _getenv("PATH");

	if (path)
		printf("PATH=%s\n", path);
}
