#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void parse_line(char *av[]);
void _exit_(char *cmd, pid_t pid, char *line);
void _env(char *cmd);

#endif
