#include "shell.h"

/***/

int _exec(char *cm, char *line)
{    
    struct stat st;
    pid_t child;
    int status, i = 1;
    char cpline[1048576], *command, *token, *arg[1024];

    strcpy(cpline, line);
    token = strtok(cpline, "\n");
    command = strtok(token, " ");

    arg[0] = command;

    /*while (command != NULL)
    {
        arg[i] = command;
        command = strtok(NULL, " ");
        i++;
    }*/
    
    if (stat(cm, &st) == 0)
    {
        child = fork();
        if (child == -1)
        {
            perror("Error process");
            return (-1);
        }
        if (child == 0)
        {
            if(execve(arg[0], arg, environ) == -1)
                perror ("Error execve");
            return (0);
        }
        else
            wait(&status);
        return (0);
    }
    else
        return (printf("command not found\n"));
}