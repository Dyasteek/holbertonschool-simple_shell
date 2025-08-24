#include "shell.h"

/**
 * commandprep - Prepare command for execution
 * @argv: Array of command arguments
 * @line: The line number
 * @original_cmd: Pointer to store original command
 *
 * Return: Full path if found, NULL if not found
 */
char *commandprep(char *argv[], int line, char **original_cmd)
{
	char *full_path;

	if (!argv[0])
		return (NULL);

	*original_cmd = malloc(strlen(argv[0]) + 1);
	if (!*original_cmd)
		return (NULL);
	strcpy(*original_cmd, argv[0]);

	full_path = commandfinder(argv[0]);
	if (!full_path)
	{
		printf("maicol: %d: %s: not found\n", line, *original_cmd);
		free(*original_cmd);
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
 * @original_cmd: Original command for error messages
 *
 * Return: 0 on success, 1 on error
 */
int forker(char *argv[], int line, char *buffer, char *full_path, char *original_cmd)
{
	pid_t pid;

	argv[0] = full_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(original_cmd);
		return (1);
	}

	if (pid == 0)
	{
		chilito(argv, line, original_cmd, buffer, original_cmd);
	}
	else
	{
		wait(NULL);
		free(original_cmd);
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
	char *full_path, *original_cmd;

	full_path = commandprep(argv, line, &original_cmd);
	if (!full_path)
		return (1);

	return (forker(argv, line, buffer, full_path, original_cmd));
}
