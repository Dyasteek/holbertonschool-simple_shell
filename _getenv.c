#include "shell.h"

/***/

char *_getenv(const char *name)
{
    char **env = environ;
    char *res, dir[strlen(name)];
    unsigned int i = 0;

    strcpy(dir, name);
    strcat(dir,"=");

    while(strncmp(env[i], dir, strlen(dir)) != 0 && env[i] != NULL)
        i++;

    if (env[i] != NULL)
    {
        char *en;
        en = malloc(strlen(env[i]));
        if(!en)
            return(NULL);
        strcpy(en, env[i]);
        char *tok = strtok(en, dir);
        res = tok;
    }
    else
        res = NULL;
    return (res);
}