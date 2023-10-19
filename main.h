#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

extern char **environ;

char *parse_line(char *av[], char *cmd);
int _getline(char **lineptr,  size_t *n, FILE *stream);
void _exit_(char *cmd, pid_t pid, char *status);
void _env(char *cmd);
void _cd(char *cmd, pid_t pid, char *newdir);
void _setenv(char *cmd, pid_t pid, char *name, char *value);
void _unsetenv(char *cmd, pid_t pid, char *name);
void check_for_builtin_commands(char *cmd, char *av[], pid_t pid, int status);
void _alias(char *cmd, pid_t pid, char *ali);
void _echo(char *cmd, pid_t pid, char *string, int status);
#endif
