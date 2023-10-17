#include "main.h"

/**
 * _env - this function handles the env builtin command for the shell (hsh)
 * @cmd: command
 *
 * Return: Nothing
 */
void _env(char *cmd)
{
	int i;

	if (strlen(cmd) == 3 && cmd[0] == 'e' && cmd[1] == 'n'
			&& cmd[2] == 'v')
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}
}
