#include "shell.h"

/**
 * commandprep - Prepare command for execution
 * @argv: Array of command arguments
 * @line: The line number
 * @cmdo: Pointer to store original command
 *
 * Return: Full path if found, NULL if not found
 */
char *commandprep(char *argv[], int line, char **cmdo)
{
	char *full_path;

	if (!argv[0])
		return (NULL);

	*cmdo = malloc(strlen(argv[0]) + 1);
	if (!*cmdo)
		return (NULL);
	strcpy(*cmdo, argv[0]);

	full_path = commandfinder(argv[0]);
	if (!full_path)
	{
		printf("maicol: %d: %s: not found\n", line, *cmdo);
		free(*cmdo);
		return (NULL);
	}

	return (full_path);
}

/**
 * forker - Execute command with fork and execve
 * @argv: Array of arguments
 * @line: Line number
 * @buffer: Buffer to free
 * @full_path: Full path to command
 * @cmdo: Original command for error messages
 *
 * Return: 0 on success, 1 on error
 */
int forker(char *argv[], int line, char *buffer, char *full_path, char *cmdo)
{
	pid_t pid;

	argv[0] = full_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmdo);
		free(full_path);
		return (1);
	}

	if (pid == 0)
	{
		chilito(argv, line, cmdo, buffer, NULL);
	}
	else
	{
		wait(NULL);
		free(cmdo);
		free(full_path);
	}
	return (0);
}

/**
 * exec - Execute a command with execve
 * @argv: Array of command arguments
 * @line: The line number
 * @buffer: The buffer to free in case of error
 *
 * Return: Always 0
 */
int exec(char *argv[], int line, char *buffer)
{
	char *full_path, *cmdo;

	full_path = commandprep(argv, line, &cmdo);
	if (!full_path)
		return (1);

	return (forker(argv, line, buffer, full_path, cmdo));
}
