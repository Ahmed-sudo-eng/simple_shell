#include "main.h"

/**
 * _exit_ -  this function is set to handle exit command in the hsh shell
 * @cmd: The command
 * @pid: The child procces identifier
 * @line: line
 * @status: child exit status
 * @user_status: status exited by the user
 *
 * Return: Nothing
 */
void _exit_(char *cmd, pid_t pid, char *line, int status, char *user_status)
{
	int s;

	if (strlen(cmd) == 4 && cmd[0] == 'e' && cmd[1] == 'x' &&
			cmd[2] == 'i' && cmd[3] == 't')
	{
		if (user_status != NULL)
		{
			s = atoi(user_status);
			free(line);
			kill(pid, 9);
			exit(s);
		}
		free(line);
		kill(pid, 9);
		exit(status / 256);
	}
}
