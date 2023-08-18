#include "shell.h"

/**
 * main - shell core function
 *
 * @ac: args counter
 * @ar: array of all args passed to main function
 *
 * Return:
 *		- interactive: 0
 *		- non_interactive: exit whit value of the execve
*/

int main(int ac, char **ar)
{
	char *buf;
	int readed;
	size_t len = 1024;
	unsigned long int iteration = 1;

	(void)ac;

	if (isatty(STDIN_FILENO) == 0)
		non_interactive(ar[0]);

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
		prompt(buf, iteration, ar[0]);
		iteration++;
	}
	return (0);
}
