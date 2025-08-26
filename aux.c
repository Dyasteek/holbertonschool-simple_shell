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
	char *cmd2;

	cmd2 = malloc(strlen(command) + 1);
	if (cmd2 == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strcpy(cmd2, command);
	token = strtok(cmd2, " \n\t");
	while (token != NULL && i < 1023)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	argv[i] = NULL;
	return (cmd2);
}

/**
 * chilito - Handle the child process execution
 * @argv: Array of arguments
 * @line: Line number
 * @command: Original command
 * @buffer: Buffer to free
 * @cmd2: Command copy to free
 *
 * Return: void
 */
void chilito(char *argv[], int line, char *command, char *buffer,
		char *cmd2)
{
	if (execve(argv[0], argv, environ) == -1)
	{
		printf("maicol: %d: %s: not found\n", line, command);
		fflush(stdout);
		free(cmd2);
		free(buffer);
		_exit(1);
	}
}

/**
 * _env - Print all environment variables
 *
 * Return: void
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}



/**
 * _exit_shell - Exit the shell
 *
 * Return: void
 */
void _exit_shell(void)
{
	fflush(stdout);
	fflush(stderr);
	_exit(0);
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
