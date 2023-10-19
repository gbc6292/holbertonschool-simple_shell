#include "shell.h"

/**
 * split_line - Split a command line into an array of arguments.
 * @line: Pointer to the line being split.
 * Return: An array of arguments (tokens).
 */
char **split_line(char *line)
{
    char **tokens = malloc(MAX_NUM_ARGS * sizeof(char *)); // Allocate memory for an array of tokens
    char *token; // Temporary storage for each token
    int position = 0; // Current position in the tokens array

    if (tokens == NULL)
    {
        return (NULL); // Return NULL in case of a memory allocation error
    }

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n"); // Print an error message if memory allocation fails
        exit(EXIT_FAILURE); // Terminate the program with an error status
    }

    token = strtok(line, " \t\r\n\a"); // Split the input line into tokens using whitespace characters
    while (token != NULL)
    {
        tokens[position] = token; // Store the token in the tokens array
        position++;

        if (position >= MAX_NUM_ARGS)
        {
            fprintf(stderr, "Too many arguments\n"); // Print an error message for too many arguments
            exit(EXIT_FAILURE); // Terminate the program with an error status
        }

        token = strtok(NULL, " \t\r\n\a"); // Move to the next token
    }

    tokens[position] = NULL; // Mark the end of the tokens array with a NULL pointer
    return (tokens); // Return the array of tokens
}
