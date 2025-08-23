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
 * pathfinder - Find command in PATH directories
 * @command: Command to find
 *
 * Return: Full path if found, NULL if not found
 */
char *pathfinder(char *command)
{
	char *path_env, *cpy_path, *current, *parser, *full_path;
	int path_len, cmd_len;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	cpy_path = malloc(strlen(path_env) + 1);
	if (!cpy_path)
		return (NULL);

	strcpy(cpy_path, path_env);
	current = cpy_path;

	while (*current)
	{
		parser = strchr(current, ':');
		if (parser)
			*parser = '\0';

		path_len = strlen(current);
		cmd_len = strlen(command);
		full_path = malloc(path_len + cmd_len + 2);

		if (!full_path)
		{
			free(cpy_path);
			return (NULL);
		}

		strcpy(full_path, current);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(cpy_path);
			return (full_path);
		}
		free(full_path);

		if (parser)
		{
			*parser = ':';
			current = parser + 1;
		}
		else
		{
			break;
		}
	}

	free(cpy_path);
	return (NULL);
}

/**
 * commandfinder - Find command (absolute path or in PATH)
 * @command: Command to find
 *
 * Return: Full path if found, NULL if not found
 */
char *commandfinder(char *command)
{
	char *cpy_path;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			cpy_path = malloc(strlen(command) + 1);
			if (cpy_path)
				strcpy(cpy_path, command);
			return (cpy_path);
		}
		return (NULL);
	}

	if ((command[0] == '.' && command[1] == '/') ||
		(command[0] == '.' && command[1] == '.' && command[2] == '/'))
	{
		if (access(command, X_OK) == 0)
		{
			cpy_path = malloc(strlen(command) + 1);
			if (cpy_path)
				strcpy(cpy_path, command);
			return (cpy_path);
		}
		return (NULL);
	}
	return (pathfinder(command));
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
		if (command2 != buffer)
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
