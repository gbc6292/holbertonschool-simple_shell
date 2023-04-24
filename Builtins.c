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

/**
 * execute_builtin - checks to see if the exectuted argument is a command
 * @command: the command being entered in the command prompt of the shell
 * @args: the arguments being analyzed to see if they're built-in
 * Return: void function
 */

void execute_builtin(char *command, char **args)
{
	if (strcmp(command, "cd") == 0)
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error");
		}
	}

	else if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * command_exists - makes sure the command exists and can be executed
 * @command: the command to be analyzed for existance
 * Return: 1 for the command existing or 0 for command not existing
 */

int command_exists(char *command, char *full_path)
{
	char *path_env = strdup(getenv("PATH"));
	char *path = strtok(path_env, ":");
       
	while (path != NULL)
	{
		snprintf(full_path, MAX_COMMAND_LEN, "%s/%s", path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_env);
			return (1);
		}
		path = strtok(NULL, ":");
	}
	free(path_env);
	return (0);
}
