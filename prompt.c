#include "shell.h"

/***/

int prompt(const char *line, int readed)
{
    char *word = malloc(strlen(line) + 1);
    if(!word)
    {
        perror("Error malloc");
        return (-1);
    }
    strcpy(word, line);

    if (readed < 0 || strcmp(line, "exit\n") == 0)
        return (lsh_exit(word));

    if (strcmp(line, "help\n") == 0)
        return (lsh_help(word));

    if (strncmp(word, "cd", 2) == 0)
        return (lsh_cd(word));

    return(_which(word));
}

int _which(char *line)
{
    /*struct stat st;*/
    char cpline[1048576];

    strcpy(cpline, line);

    char *adr = strtok(cpline, "\n");
    char *cm = strtok(adr, " ");
/*
    char *PATH = _getenv("PATH");
    char *dir = strtok(PATH, ":");

    char *cpdir = malloc(1024);
    if (!cpdir)
    {
        free(PATH);
        return (-1);
    }
    do
    {
        strcpy(cpdir, dir);
        strcat(cpdir, "/");
        strcat(cpdir, cm);
        dir = strtok(NULL, ":");
    } while (stat(cpdir, &st) != 0 && dir != NULL);
*/
    return (_exec(cm, line));
}

int lsh_exit(char* arg)
{
    free(arg);
    exit (0);
}

int lsh_help(char* arg)
{
    free(arg);
	printf("Aaron Gonzalez and Andres del Rio\n");
	printf("For more information contact us or call the police\n");

	return (0);
}

int lsh_cd(char *line)
{
    char *arg = strtok(line, "\n");
    char *args = strtok(arg, " ");

    args = strtok(NULL, " ");
    if (args == NULL)
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    else
    {
        if (chdir(args) != 0)
            perror("shell");
    }
    free(line);
    return (0);
}