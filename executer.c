#include "main.h"

/**
 * executer - a program used by the shell to execute commands
 * @cmd: command
 * @av: command with arguments
 *
 * Return: Nothing
 */
void executer(char *cmd, char *av[])
{
	char *path = getenv("PATH");
	char *token = NULL;
	char *full_path = malloc(128);

	if ((access(cmd, F_OK)) == 0)
		execve(cmd, av, environ);
	token = strtok(path, ":\n");
	while (token != NULL)
	{
		strcat(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if ((access(full_path, F_OK)) == 0)
			execve(full_path, av, environ);
		full_path[0] = '\0';
		token = strtok(NULL, ":\n");
	}
	free(full_path);
}
