#include "main.h"
/**
 * main - entry
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	char *token;
	size_t len = 0;
	int num_args;
	char *args[MAX_ARGS];

	while (1)
	{
		print_prompt();
		if (read_command(&line, &len) == -1)
		{
			break;
		}
		if (strcmp(line, "exit\n") == 0)
		{
			break;
		}
		if (strcmp(line, "\n") == 0)
		{
			continue;
		}
		num_args = 0;
		token = strtok(line, " \n");
		while (token != NULL)
		{
			args[num_args++] = token;
			token = strtok(NULL, " \n");
		}
		if (access(args[0], X_OK) != 0)
		{
			printf("'%s' is not a valid executable.\n", args[0]);
			continue;
		}
		execute_command(args);
	}
	free(line);
	return (0);
}
