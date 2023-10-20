#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

void executer(char *cmd, char *av[]);
void parse_line(char *av[]);
void _exit_(char *cmd, pid_t pid, char *line, char *status);
void _cd(char *cmd, pid_t pid, char *newdir);
void _setenv(char *cmd, pid_t pid, char *name, char *value);
void _unsetenv(char *cmd, pid_t pid, char *name);
#endif
