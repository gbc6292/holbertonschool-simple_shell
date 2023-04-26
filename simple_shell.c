#include "shell.h"

/**
 * main - fucntion to open the simple shell within the shell
 * Return: Success if the shell opens
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t READ;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
		{
		printf(PROMPT);
		fflush(stdout);
		}

		READ = getline(&line, &len, stdin);

		if (READ == -1)
		{
			/* End of file (Ctrl+D) */
			if (is_interactive)
			{
			printf("\n");
			}
			break;
		}
		if (line[READ - 1] == '\n')
		{
			/* Remove newline character */
			line[READ - 1] = '\0';
		}
		if (strlen(line) > 0)
		{
			/* Execute the command */
			execute_command(line);
		}
		if (!is_interactive)
			break;
	}
	/* Free memory and exit */
	free(line);
	return (EXIT_SUCCESS);
}
