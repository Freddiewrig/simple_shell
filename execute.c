#include "main.h"

#define MAX_INPUT_LENGTH 100
#define MAX_PATH_LENGTH 1024
/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	printf("cisfun$ ");
}

/**
 * execute_command_with_full_path - Executes the given command using fork
 * with a specified full path to the executable.
 * @command: The command to execute
 * @full_path: The full path to the executable
 * Return: 0 on success, 1 on failure
 */
int execute_command_with_full_path(char *command, char *full_path)
{
	int status;
	char *args[MAX_INPUT_LENGTH];
	int arg_count = 0;
	char *token;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (1);
	}
	if (pid == 0)
	{
		token = strtok(command, " ");
		while (token != NULL && arg_count < MAX_INPUT_LENGTH - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		execv(full_path, args);
		perror("Execution failed");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (0);
	}
}

/**
 * execute_command - Executes the given command using fork and exec,
 * searching for the command in the directories specified by the PATH.
 * @command: The command to execute
 * Return: 0 on success, 1 on failure
 */
int execute_command(char *command)
{
	char *args[MAX_INPUT_LENGTH];
	char *path_env;
	char *path_token;
	char full_path[MAX_PATH_LENGTH];
	char *token;

	token = strtok(command, " ");
	if (token == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		return (1);
	}
	args[0] = token;
	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return (1);
	}
	path_token = strtok(path_env, ":");
	while (path_token != NULL)
	{
		if (args[0][0] == '/')
		{
		snprintf(full_path, MAX_PATH_LENGTH, "%s", args[0]);
		}
		else
		{
			snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path_token, args[0]);
		}
		if (access(full_path, F_OK) != -1)
		{
			return (execute_command_with_full_path(command, full_path));
		}
		path_token = strtok(NULL, ":");
	}
	printf("Command not found: %s\n", args[0]);
	return (1);
}
