#include "shell.h"

/**
 * main - shell core function
 *
 * Return:
 *		- interactive: 0
 *		- non_interactive: exit whit value of the execve
*/

int main(void)
{
	char *buf;
	int readed;
	size_t len = 1024;
	unsigned long int iteration = 1;

	if (isatty(STDIN_FILENO) == 0)
		non_interactive();

	buf = malloc(len);
	if (!buf)
		return (1);
	while (1)
	{
		printf("$ ");
		readed = getline(&buf, &len, stdin);
		if (readed < 0)
		{
			free(buf);
			break;
		}
		while (*buf == ' ' || *buf == '\t')
			buf++;
		if (strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			break;
		}
		prompt(buf, iteration);
		iteration++;
	}
	return (0);
}
