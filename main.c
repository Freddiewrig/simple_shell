#include <stdio.h>
#include "main.h"
/**
 * main - Entry point for the simple shell program
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	int result;

	while (1)
	{
		display_prompt();
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) == 0)
		{
			continue;
		}
		result = execute_command(input);
		if (result != 0)
		{
			printf("Command execution failed.\n");
		}
	}
	return (0);
}
