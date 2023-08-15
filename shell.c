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
	size_t len = 0;

	while (1)
	{
		printf("#cisfun$ ");
		readed = getline(&buf, &len, stdin);
		prompt(buf, readed);
	}
	return (0);
}
