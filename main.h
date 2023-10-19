#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void parse_line(char *av[]);
void _exit_(char *cmd, pid_t pid, char *line, char *status);
void _cd(char *cmd, pid_t pid, char *newdir);
void _setenv(char *cmd, pid_t pid, char *name, char *value);
void _unsetenv(char *cmd, pid_t pid, char *name);
void _echo(char *cmd, pid_t pid, char *string);
#endif
