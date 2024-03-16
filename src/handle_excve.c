/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** handle_excve
*/

#include "../include/struct.h"
#include "../include/minishell.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"

int handle_excve(env_t *env, char *command)
{
    char **envp = env_to_char_array(env);
    char *delimiters = " \t\n";
    char *argv[256];
    int argc = token_command(command, delimiters, argv, 256);
    char *command_path = get_command_path(env, argv[0]);
    int pid;

    if (command_path == NULL) {
        mini_printf("%s: Command not found.\n", argv[0]);
        return 0;
    }
    pid = execute_command(command_path, argv, envp);
    return pid;
}

int token_command(char *command, char *delimiters, char **argv, int max_args)
{
    char *saveptr;
    char *arg;
    int argc = 0;

    arg = strtok_r(command, delimiters, &saveptr);
    while (arg != NULL && argc < max_args) {
        argv[argc] = arg;
        argc++;
        arg = strtok_r(NULL, delimiters, &saveptr);
    }
    argv[argc] = NULL;
    return argc;
}

int execute_command(char *command_path, char **argv, char **envp)
{
    int status;
    int pid = fork();

    if (pid == 0) {
        if (execve(command_path, argv, envp) == -1) {
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return pid;
}
