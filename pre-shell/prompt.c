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
	size_t bufsize = 10;
	ssize_t args;
	char *saveptr;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable buffer");
		exit(1);
	}

	while (1)
	{
		printf("$ ");
		args = getline(&buffer, &bufsize, stdin);

		if (args == -1 || strcmp(buffer, "end of file\n") == 0 || strcmp(buffer, "EOF\n") == 0 || strcmp(buffer, "eof\n") == 0 || strcmp(buffer, "exit\n") == 0)
		{
			printf("🏃\n");
			break;
		}
		
		const char *delimiters = " \n\t";
		token = strtok_r(buffer, delimiters, &saveptr);

		if (token != NULL)
		{
			exec(token);
		}
		token = strtok_r(NULL, delimiters, &saveptr);
	}
	free(buffer);
	return (0);
}
