#include "shell.h"

/**
 * process_command - Process a single command
 * @argv: Array of command arguments
 * @line: Line number
 * @buffer: Buffer containing the command
 *
 * Return: 0 on success, 1 on error
 */
int process_command(char *argv[], int line, char *buffer)
{
	char *cp;

	cp = tokenizer(buffer, argv);
	if (cp != NULL)
	{
		if (argv[0] != NULL)
		{
			if (strcmp(argv[0], "env") == 0)
			{
				_env();
			}
			else if (strcmp(argv[0], "exit") == 0)
			{
				_exit_shell();
			}
			else
			{
				exec(argv, line, buffer);
			}
		}
		free(cp);
		return (0);
	}
	return (1);
}

/**
 * main - Simple shell prompt that reads and executes commands
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer, *argv[1024];
	size_t bufsize = 0;
	ssize_t args;
	int line = 1;
	int interactive = isatty(STDIN_FILENO);

	buffer = NULL;

	while (1)
	{
		if (interactive)
		{
			printf("maicolyeiston$ ");
			fflush(stdout);
		}

		args = getline(&buffer, &bufsize, stdin);

		if (args == -1)
		{
			if (interactive)
				printf("🏃\n");
			break;
		}

		if (strcmp(buffer, "end of file\n") == 0 ||
			strcmp(buffer, "EOF\n") == 0 || strcmp(buffer, "eof\n") == 0)
		{
			if (interactive)
				printf("🏃\n");
			break;
		}

		process_command(argv, line, buffer);
		line++;
	}
	free(buffer);
	return (0);
}
