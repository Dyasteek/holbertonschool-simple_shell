#include "shell.h"

/**
 * non_interactive - non interactive mode of shell
*/

void non_interactive(void)
{
	char *buf, *chek_buf;
	size_t len = 1024;
	int exit_st = 0;

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
		exit_st = prompt(chek_buf);
	}
	exit(exit_st);
}
