#include "shell.h"
/**
 * execute_builtin - checks to see if the exectuted argument is a command
 * @command: the command being entered in the command prompt of the shell
 * @args: the arguments being analyzed to see if they're built-in
 * Return: void function
 */

void execute_builtin(char *command, char **args)
{
	char **env;
	(void)args;

	if (strcmp(command, "exit") == 0)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}

	else if (strcmp(command, "env") == 0)
	{
		for (env = environ; *env; ++env)
		{
			printf("%s\n", *env);
		}
	}
	if (args)
		free(args);
}

/**
 * command_exists - makes sure the command exists and can be executed
 * @command: the command to be analyzed for existance
 * Return: full_path for the command exist or NULL otherwise
 */

char *command_exists(char *command)
{
	char *path_env = getenv("PATH");
	char *path_env_copy = strdup(path_env);
	char full_path[MAX_COMMAND_LEN];
	char *saveptr;
	char *path = strtok_r(path_env_copy, ":", &saveptr);

	if (!path_env)
		return (NULL);

	if (!path_env_copy)
	{
		perror("Error");
		return (NULL);
	}

	while (path != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_env_copy);
			return (strdup(full_path));
		}
		path = strtok_r(NULL, ":", &saveptr);
	}
	free(path_env_copy);
	return (NULL);
}
