#include "shell.h"

/**
 * prompt - get all text readed and re direct it to execute
 *
 * @line: line of text
 * @readed: key for ^D
 *
 * Return: result of teh execution of the command
*/

int prompt(const char *line, int readed)
{
	char *word = malloc(strlen(line) + 1);

	if (!word)
	{
		perror("Error malloc");
		return (-1);
	}
	strcpy(word, line);

	while (*word == ' ' || *word == '\t')
		word++;

	if (readed < 0 || strcmp(word, "exit\n") == 0)
		return (lsh_exit());
	if (strcmp(word, "\n") == 0)
		return (0);

	if (strcmp(word, "help\n") == 0)
		return (lsh_help());

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
	char cpcm[1024], cpline[100000], *adr, *cm, *PATH, *dir, *cpdir;

	strcpy(cpcm, line);
	strcpy(cpline, line);

	adr = strtok(cpcm, "\n");
	cm = strtok(adr, " ");
	PATH = _getenv("PATH");
	dir = strtok(PATH, ":");

	cpdir = malloc(1024);
	if (!cpdir)
	{
		free(PATH);
		return (1);
	}

	do {
		strcpy(cpdir, dir);
		strcat(cpdir, "/");
		strcat(cpdir, cm);
		dir = strtok(NULL, ":");
	} while (stat(cpdir, &st) != 0 && dir != NULL);

	if (stat(cpdir, &st) == 0)
		return (_exec(cpdir, cpline));
	else
		return (_exec(cm, cpline));
}
