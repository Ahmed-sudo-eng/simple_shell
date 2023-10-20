#include "main.h"

/**
 * _env - this function handles the env builtin command for the shell (hsh)
 * @cmd: command
 *
 * Return: Nothing
 */
void _env(char *cmd, pid_t pid, char *av[])
{

	if (strlen(cmd) == 3 && cmd[0] == 'e' && cmd[1] == 'n'
			&& cmd[2] == 'v')
	{
		kill(pid, 9);
		execve("/bin/env", av, environ);
	}
}
