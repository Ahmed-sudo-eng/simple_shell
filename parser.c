#include "main.h"

/**
 * parse_line - This function is used to parse the user input and extract the
 * command with arguments
 * @av: an array that contains the command with arguments that will be passed
 * to the executer
 * @cmd: The command
 *
 * Return: modified command (mod_cmd)
 */
char *parse_line(char *av[], char *cmd)
{
	int i = 1;
	char *mod_cmd = NULL;

	av[0] = cmd;
	while (1)
	{
		av[i] = strtok(NULL, " \n");
		if (av[i] == NULL)
			break;
		i++;
	}
	/* This part of the code take care of the aliases */
	if (getenv(cmd) == NULL)
		mod_cmd = cmd;
	else
		mod_cmd = getenv(cmd);

	return (mod_cmd);
}
