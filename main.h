#ifndef MAIN_H
#define MAIN_H
#define MAX_INPUT_LENGTH 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void display_prompt(void);
int execute_command(char *command);
int execute_command_with_full_path(char *command, char *full_path);
#endif
