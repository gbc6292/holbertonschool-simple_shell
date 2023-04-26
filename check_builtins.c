#include "shell.h"

/**
 * is_builtin - checks to see if the command being used is a built-in
 *@command: the command being entered in the command prompt line
 *Return: 1 if the command is a built-in or 0 if not.
 */

int is_builtin(char *command)
{
	if (strcmp(command, "cd") == 0 || strcmp(command, "exit") == 0)
	{
		return (1);
	}
	return (0);
}

