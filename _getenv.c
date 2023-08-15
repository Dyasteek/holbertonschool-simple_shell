#include "shell.h"

/**
 * _getenv - get envirion name and return it
 *
 * @name: name of the envirion var
 *
 * Return: envirion content
*/

char *_getenv(const char *name)
{
	char **env = environ;
	char *res, *en, *tok, dir[strlen(name)];
	unsigned int i = 0;

	strcpy(dir, name);
	strcat(dir, "=");

	while (strncmp(env[i], dir, strlen(dir)) != 0 && env[i] != NULL)
		i++;

	if (env[i] != NULL)
	{
		en = malloc(strlen(env[i]));
		if (!en)
			return (NULL);
		strcpy(en, env[i]);
		tok = strtok(en, dir);
		res = tok;
	}
	else
		res = NULL;
	return (res);
}
