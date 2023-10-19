#include "main.h"

/**
 * parse_line - This function is used to parse the user input and extract the
 * command with arguments
 * @av: an array that contains the command with arguments that will be passed
 * to the executer
 *
 * Return: modified command (mod_cmd)
 */
void parse_line(char *av[])
{
	int i = 1;

	while (1)
	{
		av[i] = strtok(NULL, " \n");
		if (av[i] == NULL)
			break;
		i++;
	}
}
