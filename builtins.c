#include "main.h"

/**
* free_buffers - frees buffers
* @buf: buffer to be freed
*
* Return: no return
*/
void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
/**
* handle_builtin - handles execution of builtin functions
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}
/**
 *handle_signal- it keeps track is interactive mode
 *@m: the signal number
 *Return: nothing
 */

void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "cisfun$ ", 8);
}
/**
* print_prompt - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* Return: no return
*/
void print_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "cisfun$ ", 8);
}
