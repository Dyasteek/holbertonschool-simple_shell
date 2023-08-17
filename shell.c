#include "shell.h"

/**
 * main - shell core function
 *
 * Return: allways return 0
*/

int main(void)
{
	char *buf;
	int readed;
	size_t len = 1024;

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
		prompt(buf);
	}
	return (0);
}
