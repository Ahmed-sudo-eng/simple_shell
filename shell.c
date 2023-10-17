#include "main.h"
/**
 * main - a simple shell program
 * Return: On Success (0)
 */
int main(void)
{
	char *line = NULL;
	char *cmd =  malloc(16);
	char *mod_cmd =  malloc(16);
	char path[16] = {'/', 'b', 'i', 'n', '/'};
	char *av[8];
	size_t n = 0;
	int status;
	pid_t pid;
	/* Main loop */
	while (1)
	{
		/* Show ($) prompt and take input from user */
		printf("($) ");
		if ((_getline(&line, &n, stdin)) == -1)
			return (0);
		/* Parser */
		cmd = strtok(line, " \n");
		mod_cmd = parse_line(av, cmd);
		strcat(path, mod_cmd);
		/* Create the child process */
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		/* Child proccess */
		if (pid == 0)
		{
			/* Executer */
			if ((execve(path, av, environ)) == -1)
				perror(cmd);
			return (0);
		}
		/* Parent process */
		else
		{
			path[5] = '\0';
			check_for_builtin_commands(cmd, av, pid, status);
			if ((wait(&status)) == -1)
				exit(EXIT_FAILURE);
		}
	}
}
