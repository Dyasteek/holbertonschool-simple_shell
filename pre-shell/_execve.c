#include "shell.h"

int
main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("execve");
	}
	return (0);
}
