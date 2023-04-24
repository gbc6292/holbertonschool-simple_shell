#include "shell.h"

/**
 *execute_command - helps execute a command in the prompt
 *@command: the command being executed once it is written in the prompt line
 *Return: Exit error if the command couldn't be executed
*/

void execute_command(char *line)
{
	pid_t PID;
	int status;
	char **args = split_line(line);
	char full_path[MAX_COMMAND_LEN];
	char full_path_cpy[MAX_COMMAND_LEN];

	if (is_builtin(args[0]))
	{
		execute_builtin(args[0], args);
		free(args);
		return;
	}
	if (!command_exists(args[0], full_path))
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		free(args);
		return;
	}

	strcpy(full_path_cpy, full_path);

	PID = fork();
	if (PID == 0)
	{
		/* Child procces begins */
		if (execve(full_path_cpy, args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (PID < 0)
	{
		/* fork error */
		perror("Error");
	}
	else
	{
		/* Parent process */
		do {
			waitpid(PID, &status, WUNTRACED);
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(args);
}
