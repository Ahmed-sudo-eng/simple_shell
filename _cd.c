#include "main.h"

/**
 * _cd - a function to handle the cd command
 * @cmd: The command
 * @pid: The child process identifier
 * @newdir: The new directory
 */
void _cd(char *cmd, pid_t pid, char *newdir)
{
	if (strlen(cmd) == 2 && cmd[0] == 'c' && cmd[1] == 'd')
	{
		kill(pid, 9);
		if ((chdir(newdir)) == -1)
			perror(cmd);
	}
}
