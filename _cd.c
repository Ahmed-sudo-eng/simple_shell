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
		if (newdir == NULL)
		{
			newdir = getenv("HOME");
			if (newdir == NULL)
				return;
		}
		else if (*newdir == '-')
		{
			newdir = getenv("OLDPWD");
			if (newdir == NULL)
				return;
		}
		
		if ((chdir(newdir)) == -1)
			printf("./hsh: 1: cd: can't cd to %s\n", newdir);
	}
}
