#include "main.h"

/**
 * _unsetenv - Remove an environment variable
 * @cmd: command
 * @pid: child process identifier
 * @name: new environment name
 *
 * Return: Nothing
 */
void _unsetenv(char *cmd, pid_t pid, char *name)
{
	if (strlen(cmd) == 8 && cmd[0] == 'u' && cmd[1] == 'n' && cmd[2] == 's'
			     && cmd[3] == 'e' && cmd[4] == 't' && cmd[5] == 'e'
			     && cmd[6] == 'n' && cmd[7] == 'v')
	{
		kill(pid, 9);
		if ((unsetenv(name)) == -1)
			perror("./hsh");
	}
}
