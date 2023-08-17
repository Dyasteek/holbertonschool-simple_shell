#include "shell.h"

/**
 * prompt - get all text readed and re direct it to execute
 *
 * @line: line of text
 * @readed: key for ^D
 *
 * Return: result of teh execution of the command
*/

int prompt(char *line)
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
	if (strncmp(word, "cd", 2) == 0)
		return (lsh_cd(word));

	return (_which(word));
}

/**
 * _which - convert the line of text to command
 *
 * @line: line of text
 *
 * Return: result of execution
*/

int _which(char *line)
{
	struct stat st;
	char cpcm[1024], cpline[100000], cpPATH[1000000];
	char *adr, *command, *dir, cpdir[1024];

	strcpy(cpcm, line);
	strcpy(cpline, line);

	adr = strtok(cpcm, "\n");
	command = strtok(adr, " ");
	strcpy(cpPATH, _getenv("PATH"));
	dir = strtok(cpPATH, ":");

	do {
		strcpy(cpdir, dir);
		strcat(cpdir, "/");
		strcat(cpdir, command);
		dir = strtok(NULL, ":");
	} while (stat(cpdir, &st) != 0 && dir != NULL);

	free(line);

	if (stat(cpdir, &st) == 0)
		return (_exec(cpdir, cpline));
	else
		return (_exec(command, cpline));
}
