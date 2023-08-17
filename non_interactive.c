#include "shell.h"

/**
 * non_interactive - non interactive mode of shell
*/

void non_interactive(void)
{
	char *buf;
	int readed;
	size_t len = 1024;
    int exit_st = 0;

    buf = malloc(len);
	if (!buf)
		exit(1);
	while (1)
	{
	    readed = getline(&buf, &len, stdin);
        if (readed < 0)
	    {
		    free(buf);
		    break;
	    }
	    while (*buf == ' ' || *buf == '\t')
		    buf++;
		exit_st = prompt(buf);
	}
    exit(exit_st);
}