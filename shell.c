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
			chdir("/bin");
			if ((execve(av[0], av, environ)) == -1)
				perror(av[0]);
			return (0);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
