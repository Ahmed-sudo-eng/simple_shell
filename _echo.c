#include "main.h"

/**
 * _echo - a function prints a string to standard output
 * @cmd: command
 * @pid: child process identifier
 * @string: string to print
 * @status: last command exit status
 *
 * Return: Nothing
 */
void _echo(char *cmd, pid_t pid, char *string, int status)
{
	if (strlen(cmd) == 4 && cmd[0] == 'e' && cmd[1] == 'c' && cmd[2] == 'h'
			     && cmd[3] == 'o')
	{
		kill(pid, 9);
		if (string[0] == '$')
		{
			switch (string[1])
			{
				case '$':
					printf("%u\n", getpid());
					break;
				case '?':
					printf("%d\n", status / 256);
					break;
			}
		}
	}
}
