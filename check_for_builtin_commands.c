#include "main.h"

/**
 * check_for_builtin_commands - Every time the user enter a command this
 * function checks if its a one of the defined builtin commands
 * @cmd: command
 * @av: an array that contains arguments
 * @pid: child peocess identifier
 * @status: The exit status of the last command
 *
 * Return: Nothing
 */
void check_for_builtin_commands(char *cmd, char *av[], pid_t pid, int status)
{
	_exit_(cmd, pid, av[1]);
	_env(cmd);
	_cd(cmd, pid, av[1]);
	_setenv(cmd, pid, av[1], av[2]);
	_unsetenv(cmd, pid, av[1]);
	_alias(cmd, pid, av[1]);
	_echo(cmd, pid, av[1], status);
}
