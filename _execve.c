#include "shell.h"

/**
 * exec - Execute a command with execve
 * @command: The command to execute
 * @line: The line number
 * @buffer: The buffer to free in case of error
 *
 * Return: Always 0
 */
int exec(char *command, int line, char *buffer)
{
	pid_t pid;
	char *argv[1024];
	char *command2;

	command2 = tokenizer(command, argv);
	if (command2 == NULL)
		return (1);

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(command2);
		return (1);
	}

	if (pid == 0)
	{
		chilito(argv, line, command, buffer, command2);
	}
	else
	{
		wait(NULL);
	}
	free(command2);
	return (0);
}
