#include "shell.h"

/**
 * _getenv - get the value of an env
 * @name: the name of the env variable
 * Return: env value
 */
char *_getenv(const char *name)
{
	size_t len, i;
	char *env;

	if (name == NULL || environ == NULL)
		return (NULL);

	len = strlen(name);
	i = 0;

	while (environ[i])
	{
		env = environ[i];
		if (strncmp(env, name, len) == 0 && env[len] == '=')
		{
			return (env + len + 1);
		}
		i++;
	}
	return (NULL);
}
