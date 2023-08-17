#include "shell.h"

/**
 * main - shell core function
 *
 * Return: allways return 0
*/

int main(void)
{
	char *buf;
	int readed, interactive = 0, res = 0;
	size_t len = 1024;

	buf = malloc(len);
	if (!buf)
		return (1);

	if (isatty(STDIN_FILENO) == 1)
		interactive = 1;

	while (1)
	{
		if (interactive == 1)
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
		res = prompt(buf);
	}
	if (interactive == 1)
		return (0);
	else
		return (res);
}
