#include "shell.h"

/**
 * _getenv - get envirion name and return it
 *
 * @name: name of the envirion var
 *
 * Return: envirion content
*/

char *_getenv(char *name)
{
	size_t name_len, i;
	char *result;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_len = strlen(name);
	result = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 &&
			environ[i][name_len - 1] == '=')
		{
			result = &environ[i][name_len];
			break;
		}
	}

	return (result);
}
