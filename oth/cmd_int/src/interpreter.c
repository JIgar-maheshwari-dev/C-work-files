#include"head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int execute_command(char *args[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return -1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

void call() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        // Print prompt
        printf("$ ");
        
        // Read command from user
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';  // Remove newline character

        // Tokenize command into arguments
        char *token = strtok(command, " ");
        int arg_count = 0;
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Execute command
        if (arg_count > 0) {
            if (strcmp(args[0], "exit") == 0) {
                // Exit shell
                break;
            } else if (strcmp(args[0], "cd") == 0) {
                // Change directory
                if (arg_count != 2) {
                    fprintf(stderr, "Usage: cd <directory>\n");
                } else {
                    if (chdir(args[1]) != 0) {
                        perror("cd failed");
                    }
                }
            } else {
                // Execute external command
                execute_command(args);
            }
        }
    }


}

