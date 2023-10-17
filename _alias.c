#include "main.h"

/**
 * _alias - make an alias for a command
 * @cmd: command
 * @pid: child process identifier
 * @ali: alias int the form name=value
 *
 * Return: NULL
 */
void _alias(char *cmd, pid_t pid, char *ali)
{
	if (strlen(cmd) == 5 && cmd[0] == 'a' && cmd[1] == 'l' && cmd[2] == 'i'
			     && cmd[3] == 'a' && cmd[4] == 's')
	{
		kill(pid, 9);
		if (ali == NULL)
		{
			printf("I will print all the aliases\n");
		}
		else
			putenv(ali);
	}
}
