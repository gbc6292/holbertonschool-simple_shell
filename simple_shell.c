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

	while (1)
	{

	printf(PROMPT);
	fflush(stdout);
	READ = getline(&line, &len, stdin);

		if (READ == -1)
		{
			/* End of file (Ctrl+D) */
			printf("\n");
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
	}

	/* Free memory and exit */
	free(line);

	return (EXIT_SUCCESS);
}
