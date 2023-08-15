#include "shell.h"

/**
 * main - shell core function
 *
 * Return: allways return 0
*/

int main(void)
{
	char *exit = "exit", *buf;
	pid_t child;
	int readed;
	int res;
	size_t len = 0;

	buf = malloc(len);
	if (!buf)
		return (-1);

	while (1)
	{
		printf("#cisfun$ ");
		readed = getline(&buf, &len, stdin);
		res = prompt(buf, readed);
	}
	return (0);
}
