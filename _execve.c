#include "shell.h"

/**
 * _exec - function to execute a command line
 *
 * @com: command to execute
 * @line: line whith content all arguments
 *
 * Return:
 *      - an error
 *      - 0 success
 *      - command not found
*/

int _exec(char *com, char *line)
{
	struct stat st;
	pid_t child;
	int status, i = 1;
	char cpline[1048576], *command, *token, *arg[1024];

	strcpy(cpline, line);
	token = strtok(cpline, "\n");
	command = strtok(token, " ");

	arg[0] = com;

	while (command != NULL)
	{
		command = strtok(NULL, " ");
		arg[i] = command;
		i++;
	}

	if (stat(arg[0], &st) == 0)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error process");
			return (1);
		}
		if (child == 0)
		{
			if (execve(arg[0], arg, environ) == -1)
				perror("Error execve");
		}
		else
			wait(&status);
		return (0);
	}
	else
		return (fprintf(stderr, "./shell: No such file or directory\n"));
}

/**
 * lsh_help - print help of the shell
 *
 * Return: allways return 0
*/

int lsh_help(void)
{
	printf("Aaron Gonzalez and Andres del Rio\n");
	printf("For more information contact us or call the police\n");

	return (0);
}

/**
 * lsh_cd - change the shell actual directory
 *
 * @line: line of text whith contains all arguments
 *
 * Return: allways return 0
*/

int lsh_cd(char *line)
{
	char *arg = strtok(line, "\n");
	char *args = strtok(arg, " ");

	args = strtok(NULL, " ");
	if (args == NULL)
		fprintf(stderr, "./shell: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args) != 0)
			perror("./shell");
	}
	free(line);
	return (0);
}
