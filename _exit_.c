#include "main.h"

/**
 * _exit_ -  this function is set to handle exit command in the hsh shell
 * @cmd: The command
 * @pid: The child procces identifier
 * @line: line
 *
 * Return: Nothing
 */
void _exit_(char *cmd, pid_t pid, char *line, char *status)
{
	int s;

	if (strlen(cmd) == 4 && cmd[0] == 'e' && cmd[1] == 'x' &&
			cmd[2] == 'i' && cmd[3] == 't')
	{
		if (status == NULL)
			s = 0;
		else
			s = atoi(status);
		free(line);
		kill(pid, 9);
		exit(s);
	}
}