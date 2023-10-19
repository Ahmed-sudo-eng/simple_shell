#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - a simple shell program
 *
 * Return: On Success (0)
 */
int main(void)
{
	char *line = NULL;
	char *cmd =  malloc(16);
	char *av[8];
	size_t n = 0;
	int status;
	pid_t pid;

	/* Main loop */
	while (1)
	{
		/* Show ($) prompt and take input from user */
		/*printf("#cisfun$ ");*/
		if ((getline(&line, &n, stdin)) == -1)
			return (0);
		/* Parser */
		cmd = strtok(line, " \n");
		av[0] = cmd;
		av[1] = NULL;
		/* Create the child process */
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			if ((execve(cmd, av, NULL)) == -1)
				perror(cmd);
			return (0);
		}
		else
		{
			if ((wait(&status)) == -1)
				exit(EXIT_FAILURE);
		}
	}
}
