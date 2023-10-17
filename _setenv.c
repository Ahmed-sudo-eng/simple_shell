#include "main.h"

/**
 * _setenv - this function initialize a new environment variable, or modifiy an
 * existing one
 * @cmd: command
 * @pid: child process identifier
 * @name: new environment name
 * @value: new environment value
 *
 * Return: Nothing
 */
void _setenv(char *cmd, pid_t pid, char *name, char *value)
{
	if (strlen(cmd) == 6 && cmd[0] == 's' && cmd[1] == 'e' && cmd[2] == 't'
			     && cmd[3] == 'e' && cmd[4] == 'n'
			     && cmd[5] == 'v')
	{
		kill(pid, 9);
		if (name == NULL || value == NULL)
			return;
		if ((setenv(name, value, 1)) == -1)
			perror("./hsh");
	}
}
