#include "shell.h"

/**
 * pathbuilder - Build full path by combining directory and command
 * @current: Current directory path
 * @command: Command to find
 *
 * Return: Full path if built successfully, NULL on error
 */
char *pathbuilder(char *current, char *command)
{
	char *full_path;
	int path_len, cmd_len;

	path_len = strlen(current);
	cmd_len = strlen(command);
	full_path = malloc(path_len + cmd_len + 2);

	if (!full_path)
		return (NULL);

	strcpy(full_path, current);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}

/**
 * pathchecker - Check if command exists in current directory
 * @current: Current directory path
 * @command: Command to find
 * @cpy_path: Copy of PATH for cleanup
 *
 * Return: Full path if found, NULL if not found
 */
char *pathchecker(char *current, char *command, char *cpy_path)
{
	char *full_path;

	full_path = pathbuilder(current, command);
	if (!full_path)
		return (NULL);

	if (access(full_path, X_OK) == 0)
	{
		free(cpy_path);
		return (full_path);
	}

	free(full_path);
	return (NULL);
}

/**
 * pathfinder - Find command in PATH directories
 * @command: Command to find
 *
 * Return: Full path if found, NULL if not found
 */
char *pathfinder(char *command)
{
	char *path_env, *cpy_path, *current, *parser, *full_path;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	cpy_path = malloc(strlen(path_env) + 1);
	if (!cpy_path)
		return (NULL);

	strcpy(cpy_path, path_env);
	current = cpy_path;

	while (*current)
	{
		parser = strchr(current, ':');
		if (parser)
			*parser = '\0';

		full_path = pathchecker(current, command, cpy_path);
		if (full_path)
			return (full_path);

		if (parser)
		{
			*parser = ':';
			current = parser + 1;
		}
		else
		{
			break;
		}
	}

	free(cpy_path);
	return (NULL);
}

/**
 * commandfinder - Find command (absolute path or in PATH)
 * @command: Command to find
 *
 * Return: Full path if found, NULL if not found
 */
char *commandfinder(char *command)
{
	char *cpy_path;

	if (command[0] == '/')
	{
		if (access(command, X_OK) == 0)
		{
			cpy_path = malloc(strlen(command) + 1);
			if (cpy_path)
				strcpy(cpy_path, command);
			return (cpy_path);
		}
		return (NULL);
	}

	if ((command[0] == '.' && command[1] == '/') ||
		(command[0] == '.' && command[1] == '.' && command[2] == '/'))
	{
		if (access(command, X_OK) == 0)
		{
			cpy_path = malloc(strlen(command) + 1);
			if (cpy_path)
				strcpy(cpy_path, command);
			return (cpy_path);
		}
		return (NULL);
	}

	return (pathfinder(command));
}
