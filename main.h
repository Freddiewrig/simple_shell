#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_PATH_LENGTH 1024
#define MAX_ARGS 100
void print_prompt(void);
int read_command(char **line, size_t *len);
void execute_with_path(char *command);
void execute_command(char *args[]);
#endif
