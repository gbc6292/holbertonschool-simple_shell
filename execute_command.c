#include "shell.h"

/**
 * execute_command - Execute a command in the shell prompt.
 * @line: The command to be executed, entered in the prompt line.
 * Return: No explicit return value. Handles command execution and errors.
 */
void execute_command(char *line)
{
    pid_t PID;
    int status;
    char **args = split_line(line); // Split the input line into arguments
    char *full_path = NULL;

    if (is_builtin(args[0]))
    {
        execute_builtin(args[0], args); // Execute a built-in command
        return;
    }

    if (args[0][0] == '.' || args[0][0] == '/')
    {
        if (access(args[0], X_OK) == 0)
        {
            full_path = args[0]; // Use the provided path if it's executable
        }
    }
    else
        full_path = command_exists(args[0]); // Check if the command exists in the PATH

    if (!full_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]); // Print an error if the command is not found
        free(args); // Free memory allocated for arguments
        return;
    }

    PID = fork(); // Create a new process
    if (PID == 0)
    {
        /* Child process begins */
        if (execve(full_path, args, environ) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE); // Handle execution error
        }
    }
    else if (PID < 0)
    {
        /* Fork error */
        perror("Error");
    }
    else
    {
        /* Parent process */
        do {
            waitpid(PID, &status, WUNTRACED); // Wait for the child process to finish
        } while (!WIFEXITED(status) && !WIFSIGNALED(status);
    }

    if (full_path != args[0])
        free(full_path); // Free memory allocated for the full_path

    if (args)
        free(args); // Free memory allocated for arguments
}
