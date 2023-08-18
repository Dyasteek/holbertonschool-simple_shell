#include "shell.h"

/**
 * prompt - get all text readed and re direct it to execute
 *
 * @line: line of text
 * @iteration: number of the line in execution
 * @exe: name of the executable shell
 *
 * Return: result of teh execution of the command
*/

int prompt(char *line, unsigned long int iteration, char *exe)
{
	char *word = malloc(strlen(line) + 1);

	if (!word)
	{
		perror("Error malloc");
		return (1);
	}
	strcpy(word, line);

	if (strcmp(word, "\n") == 0)
	{
		free(word);
		return (0);
	}
	if (strcmp(word, "help\n") == 0)
	{
		free(word);
		return (lsh_help());
	}
	if (strcmp(word, "env\n") == 0)
	{
		free(word);
		return (lsh_env());
	}
	if (strncmp(word, "cd", 2) == 0)
		return (lsh_cd(word, exe));

	return (_which(word, iteration, exe));
}

/**
 * _which - convert the line of text to command
 *
 * @line: line of text
 * @iteration: number of the line in execution
 * @exe: name of the executable shell
 *
 * Return: result of execution
*/

int _which(char *line, unsigned long int iteration, char *exe)
{
	struct stat st;
	int exit_stat;
	char cpPATH[1000000], cpdir[1024];
	char *adr, *command, *dir, *duplicate;

	adr = strtok(line, "\n");

	duplicate = strdup(adr);
	command = strtok(duplicate, " ");
	if (_getenv("PATH=") != NULL && strcmp(_getenv("PATH="), "") != 0)
	{
		strcpy(cpPATH, _getenv("PATH="));
		dir = strtok(cpPATH, ":");

		do {
			strcpy(cpdir, dir);
			strcat(cpdir, "/");
			strcat(cpdir, command);
			dir = strtok(NULL, ":");
		} while (stat(cpdir, &st) != 0 && dir != NULL);

		if (stat(cpdir, &st) == 0)
			exit_stat = _exec(cpdir, adr, iteration, exe);
		else
			exit_stat = _exec(command, adr, iteration, exe);
	}
	else
	{
		if (strncmp(command, "/", 1) == 0 || strncmp(command, "./", 2) == 0)
			exit_stat = _exec(command, adr, iteration, exe);
		else
		{
			fprintf(stderr, "%s: %li: %s: not found\n", exe, iteration, command);
			exit_stat = 127;
		}
	}
	free(duplicate);
	free(adr);
	return (exit_stat);
}
