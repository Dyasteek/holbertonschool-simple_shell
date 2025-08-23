#include "shell.h"

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
	pid_t pid;
	char *full_path, *original_cmd, *allocated_path;

	if (!argv[0])
		return (0);

	/* Store original command for error message */
	original_cmd = malloc(strlen(argv[0]) + 1);
	if (!original_cmd)
		return (1);
	strcpy(original_cmd, argv[0]);

	/* Find the command in PATH or check if absolute path exists */
	full_path = commandfinder(argv[0]);
	if (!full_path)
	{
		printf("maicol: %d: %s: not found\n", line, original_cmd);
		free(original_cmd);
		return (1);
	}

	/* Store the allocated path for later cleanup */
	allocated_path = full_path;

	/* Replace argv[0] with the full path */
	argv[0] = full_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(original_cmd);
		free(allocated_path);
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
		free(allocated_path);
	}
	return (0);
}
