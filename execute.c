#include "pre_shell.h"

char *builting_str[] = {"cd", "help"};

int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help};

/*size of builitn that return size*/
int lsh_num_builtins(void)
{
    return (sizeof(builtin_str) / sizeof(char *));
}

/*builtin to change dirs - if success return 1*/
int lsh_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd"\n"");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("shell");
        }
    }
    return (1);
}

/*print the help for the shell - always return 1 to continue executing*/
int lsh_help(char **args)
{
	int i;

	printf("Aaron Gonzalez and Andres del Rio\n");
	printf("For more information contact us or call the police\n");
	(void)args;
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	return (1);
}

/*builtin to exit the shell*/
int lsh_exit(char **args)
{
	(void)args; //ignore the adv about not used args
	printf("should exit\n"); //print the message
	free(args); //free args
	return (1); //return 1 if ok
}

/*our own fork (? */
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
    pid_t child;  // Variable that allow the child
    int status, i = 0;  // child status and counter
    char *format = "%s: %d: %s: not fund\n";  // error

    if (arg[0] == NULL)
        return (1);  // without args return 1

    for (i = 0; i < lsh_num_builtins(); i++)
    {
        if (_strcmp(arg[0], builtin_str[i]) == 0)
            return (builtin_func[i](arg));  // for the local command, execute the correct function
    }

    child = fork();  // make a child

    if (child == 0)
    {
        if (execve(arg[0], arg, env) == -1)  // try to execute the command
        {
            fprintf(stderr, format, av[0], np, arg[0]);  // print the error if the comand not fund
            if (!c)
                free(arg[0]);  // free the arg mem if the concatenate mode is not especified
            free(arg);  // free args
            free(lineptr);  // free line
            exit(errno);  // exit with the correct error code
        }
    }
    else
    {
        wait(&status);  // wait and get for the child proces
        return (status);  // return the status of child
    }
    return (0);  // return 0 if all ok
}

