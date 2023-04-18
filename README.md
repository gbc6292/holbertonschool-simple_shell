# Creating a Basic Shell in C

A shell is a command-line interface that allows users to interact with the operating system by entering commands.  Here we'll discuse how to create a basic shell.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Implementation](#implementation)
  - [Reading User Input](#reading-user-input)
  - [Tokenizing Input](#tokenizing-input)
  - [Executing Commands](#executing-commands)
  - [Main Loop](#main-loop)
- [Code Example](#code-example)
- [Building and Running the Shell](#building-and-running-the-shell)

## Introduction

A basic shell typically follows these steps:

1. Display a prompt for the user.
2. Read the user's input.
3. Parse the input into command and arguments.
4. Execute the command.
5. Repeat steps 1-4 until the user decides to exit the shell.

We'll use standard C libraries and system calls to implement our basic shell

## Requirements

- The Shell should be both interactive and non-interactive
- A C compiler (e.g., GCC)
- A text editor or IDE for writing C code
- Basic understanding of the C programming language
- Familiarity with UNIX system calls and functions

## Implementation

### Reading User Input

To read user input, we will use the `fgets` function to read a line of text from `stdin`. We'll store the input in a dynamically allocated buffer using `malloc`.

### Tokenizing Input

We'll tokenize the input line into command and arguments using the `strtok` function, which splits the input based on specified delimiters (e.g., space, tab, newline).

### Executing Commands

To execute the Command, we'll use the `fork` system call to createa child process. The child process will execute the commandusing the `execve`function, while the parent process will wait for the child process to finish using `waitpid`.

### Main Loop

The main loop of our shell will display a prompt, read user input, tokenize the input, and execute the command. This loop will continue until the user decides to exit the shell.

## Code Example




## Building and Running the Shell

To build and run the shell, follow this steps:

1. Save the code example in a file named `simple_shell.c`.
2. Open a terminal and navigate to the directory containing the `simple_shell.c` file.
3. Compile the code using the following command: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
4. Run the compiled executable with this command: ./simple_shell

You should now see the shell prompt, and you can enter commands to execute them. To exit the shell, press Ctrl+D or enter the `exit` command.
