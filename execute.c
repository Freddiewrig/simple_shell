#include "main.h"
/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * read_command - Reads a command from the user.
 * @line: Pointer to the buffer where the command is stored.
 * @len: Maximum length of the buffer.
 *
 * Return: The number of bytes read, or -1 on failure.
 */
int read_command(char **line, size_t *len)
{
	ssize_t nread;

	nread = getline(line, len, stdin);
	return (nread);
}
/**
 * execute_command - Executes a command in a child process.
 * @args: Array of command arguments.
 */
void execute_command(char *args[])
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
/**
 * execute_with_path - Execute a command using the PATH environment variable.
 * @command: The command to execute.
 *
 * This function attempts to execute the specified command by searching for
 * it in the directories listed in the PATH environment variable. If the
 * command is found and is executable, it is executed. If not found or not
 * executable, an appropriate message is displayed.
 */
void execute_with_path(char *command)
{
	char *path;
	int is_ls;
	char *dir;
	char *path_copy;
	char executable[MAX_PATH_LENGTH];
	char *args[2];

	path = getenv("PATH");
	if (path == NULL)
	{
		printf("Could not get PATH environment variable.\n");
		return;
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Memory allocation failed");
		return;
	}
	dir = strtok(path_copy, ":");
	is_ls = (strcmp(command, "ls") == 0);
	while (dir != NULL)
	{
		snprintf(executable, MAX_PATH_LENGTH, "%s/%s", dir, command);
		if ((access(executable, X_OK) == 0)
			&& (is_ls || strcmp(command, executable) == 0))
		{
			args[0] = executable;
			args[1] = NULL;
			execute_command(args);
			free(path_copy);
			return;
		}
		dir = strtok(NULL, ":");
	}
	printf("%s: command not found\n", command);
	free(path_copy);
}
