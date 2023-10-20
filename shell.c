#include "main.h"

/**
 * main - a simple shell program
 *
 * Return: On Success (0)
 */
int main(void)
{
	char *line = NULL;
	char *av[16];
	size_t n = 0;
	pid_t pid;

	/* Main loop */
	while (1)
	{
		/* Show ($) prompt and take input from user */
		/*printf("($) ");*/
		if ((getline(&line, &n, stdin)) == -1)
			break;
		/* Parser */
		av[0] = strtok(line, " \n");
		parse_line(av);
		/* Create the child process */
		pid = fork();
		if (pid == 0)
		{
			executer(av[0], av);
			return (0);
		}
		else
		{
			/*
			_exit_(av[0], pid, line, av[1]);
			_cd(av[0], pid, av[1]);
			_setenv(av[0], pid, av[1], av[2]);
			_unsetenv(av[0], pid, av[1]);
			 */
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
