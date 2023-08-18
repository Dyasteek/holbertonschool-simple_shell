#include "shell.h"

/**
 * non_interactive - non interactive mode of shell
 *
 * @exe: name of the executable shell
*/

void non_interactive(char *exe)
{
	char *buf, *chek_buf;
	size_t len = 1024;
	int exit_st = 0;
	unsigned long int iteration = 1;

	buf = malloc(len);
	if (!buf)
		exit(1);
	while (1)
	{
		if (getline(&buf, &len, stdin) == -1)
		{
			free(buf);
			break;
		}
		chek_buf = buf;
		while (*chek_buf == ' ' || *chek_buf == '\t')
			chek_buf++;
		if (strcmp(buf, "exit\n") == 0)
		{
			free(buf);
			break;
		}
		exit_st = prompt(chek_buf, iteration, exe);
		iteration++;
	}
	exit(exit_st);
}
