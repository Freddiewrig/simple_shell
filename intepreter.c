#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXIMUM_LINE_LENGTH 80
#define MAXIMUM_ARGS 10
/**
 * main - creates a shell
 * @line: maximum length of line
 * @args: maximum number of arguments
 * @state: status of shell
 * Return: 0 (Success)
 */
int main(char line[MAXIMUM_LINE_LENGTH], char *args[MAXIMUM_ARGS], int state)
{
while (1)
{
printf("simple_shell ");
fgets(line, MAXIMUM_LINE_LENGTH, stdin);
int j = 0;
args[j] = strtok(line, "\n");
while (args[j] != NULL)
{
j++;
args[j] = strtok(NULL, "\n");
}
args[j] = NULL;
if (strcmp(args[0], "cd") == 0)
{
chdir(args[1]);
continue;
}
else if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
pid_t pid = fork();
if (pid < 0)
{
perror("fork has failed");
exit(1);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("execvp has failed");
exit(1);
}
else
{
waitpid(pid, &state, 0);
}
}
return (0);
}
