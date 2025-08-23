#include "shell.h"

/**
 * main - Simple shell prompt that reads and executes commands
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer, *cp, *argv[1024];
	size_t bufsize = 0;
	ssize_t args;
	int line = 1;

	buffer = NULL;

	while (1)
	{
		printf("maicolyeiston$ ");
		fflush(stdout);
		args = getline(&buffer, &bufsize, stdin);

		if (args == -1 || strcmp(buffer, "end of file\n") == 0 ||
			strcmp(buffer, "EOF\n") == 0 || strcmp(buffer, "eof\n") == 0 ||
			strcmp(buffer, "exit\n") == 0)
		{
			printf("🏃\n");
			break;
		}

		cp = tokenizer(buffer, argv);
		if (argv[0] != NULL)
		{
			if (strcmp(argv[0], "env") == 0)
			{
				print_env();
			}
			else
			{
				exec(argv, line, buffer);
			}
			free(cp);
			line++;
		}
	}
	free(buffer);
	return (0);
}
