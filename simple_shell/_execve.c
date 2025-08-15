#include "shell.h"

/**
 * exec - Execute a command with execve
 * @command: The command to execute
 *
 * Return: Always 0
 */
int exec(char *command)
{
	pid_t pid;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	} else {
		wait(NULL);
	}

	return (0);
}
