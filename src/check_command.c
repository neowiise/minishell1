/*
** EPITECH PROJECT, 2024
** minishelll
** File description:
** check_command
*/

#include "../include/proto.h"
#include "../include/minishell.h"
#include "../include/struct.h"
#include "../lib/mini_printf.h"

int handle_command(env_t **env, char *command)
{
    char **args;

    if (my_strncmp("cd", command, 2) == 0) {
        args = parse_args(command);
        my_cd(env, args);
        free(args);
        return (0);
    }
    if (my_strcmp("exit", command) == 0) {
        exit(EXIT_SUCCESS);
    }
    if (my_strcmp("exitt", command) == 0) {
        mini_printf("%s: Command not found.\n", command);
        return (0);
    }
    return (1);
}

int handle_env_command(env_t **env, char *command)
{
    char **args;

    if (my_strncmp("env", command, 3) == 0) {
        print_env_list(env);
        return (0);
    }
    if (my_strncmp("unsetenv", command, 8) == 0) {
        args = parse_args(command);
        my_unset_env(env, args[1]);
        return (0);
    }
    if (my_strncmp("setenv", command, 6) == 0) {
        args = parse_args(command);
        my_set_env(env, args[1], args[2]);
        return (0);
    }
    return (1);
}

int process_command(env_t **env, char *command)
{
    int result;

    result = handle_command(env, command);
    if (result == 0) {
        return 0;
    }
    result = handle_env_command(env, command);
    if (result == 0) {
        return 0;
    }
    return 1;
}

char **parse_args(char *command)
{
    char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
    char *arg;
    int i;

    if (args == NULL) {
        exit(EXIT_FAILURE);
    }
    i = 0;
    arg = strtok(command, " \t\n;");
    for (int j = 0; j < MAX_ARGS -1; j++)
        args[j] = NULL;
    while (arg != NULL && i < MAX_ARGS - 1) {
        args[i] = arg;
        i++;
        arg = strtok(NULL, " \t\n;");
    }
    args[i] = NULL;
    return args;
}

char **parse_command(char *command)
{
    char **commands = malloc((MAX_COMMANDS + 1) * sizeof(char *));
    int num_commands = 0;
    char *token = strtok(command, ";");

    while (token != NULL && num_commands < MAX_COMMANDS) {
        commands[num_commands] = my_strdup(token);
        num_commands++;
        token = strtok(NULL, ";");
    }
    commands[num_commands] = NULL;
    return commands;
}
