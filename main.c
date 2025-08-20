#include "shell.h"

/**
 * main - Simple shell prompt that reads and executes commands
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer;
	char *token;
	size_t bufsize = 0;
	ssize_t args;
	int line = 1;
	const char *delimiters = " \n\t";

	buffer = NULL;

	while (1)
	{
		printf("shellyBean$: ");
		fflush(stdout);
		args = getline(&buffer, &bufsize, stdin);

		if (args == -1 || strcmp(buffer, "end of file\n") == 0 || strcmp(buffer, "EOF\n") == 0 || strcmp(buffer, "eof\n") == 0 || strcmp(buffer, "exit\n") == 0)
		{
			printf("🏃\n");
			break;
		}

		token = strtok(buffer, delimiters);
		if (token != NULL)
		{
			exec(token, line, buffer);
		}
		line++;
	}
	free(buffer);
	return (0);
}
