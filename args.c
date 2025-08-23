#include <stdio.h>
/**
 * main - prints all the arguments
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char **av)
{
	int i;
	(void)ac;
	for (i = 0; av[i] != NULL; i++)
	{
		printf("%d: %s\n", i, av[i]);
	}
	return (0);
}
