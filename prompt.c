#include "shell.h"

/**
 * prompt - get all text readed and re direct it to execute
 * 
 * Return: result of teh execution of the command
*/

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
        return (lsh_exit());

    if (strcmp(line, "help\n") == 0)
        return (lsh_help());

    if (strncmp(word, "cd", 2) == 0)
        return (lsh_cd(word));

    return(_which(word));
}

/**
 * _which - convert the line of text to command
 * 
 * Return: result of execution
*/

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