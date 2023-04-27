#include "shell.h"


/**
 * split_line - split command line into array of arguments
 * @line: pointer to the line being split
 * Return: the arguments split
*/

char **split_line(char *line)
{
	char **tokens = malloc(MAX_NUM_ARGS * sizeof(char *));
	char *token;
	int position = 0;

	if (tokens == NULL)
	{
		free(tokens);
		return(NULL);
	}

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= MAX_NUM_ARGS)
		{
			fprintf(stderr, "Too many arguments\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[position] = NULL;
	return (tokens);
}
