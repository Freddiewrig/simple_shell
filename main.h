#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int check_built(char **cmd, char *buf);
void print_prompt(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_env(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);
/**
 * struct builtin - Structure representing built-in commands
 *
 * @env: Pointer to environment information
 * @exit: Pointer to exit command
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;
/**
 * struct info - Structure containing additional information
 *
 * @final_exit: Final exit code
 * @ln_count: Line count
 */
struct info
{
	int final_exit;
	int ln_count;
} info;
/**
 * struct flags - Structure for managing flags
 *
 * @interactive: Flag indicating interactive mode
 */
struct flags
{
	bool interactive;
} flags;

#endif /* MAIN_H */
