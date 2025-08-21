#include "shell.h"

/**
 * exec - Execute a command with execve
 * @command: The command to execute
 * @line: The line number
 * @buffer: The buffer to free in case of error
 *
 * Return: Always 0
 */
int exec(char *argv[], int line, char *buffer)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		chilito(argv, line, argv[0], buffer, NULL);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
