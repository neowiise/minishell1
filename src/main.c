/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** main
*/

#include "../include/proto.h"
#include "../include/struct.h"
#include "../include/minishell.h"

void free_all(env_t *env)
{
    env_t *current_elem = env->next;
    env_t *next_elem;

    while (current_elem != NULL) {
        next_elem = current_elem->next;
        free(current_elem);
        current_elem = next_elem;
    }
}

void process_and_handle_command(env_t **env, char *command)
{
    if (process_command(env, command) == 1) {
        handle_excve(*env, command);
    }
}

int main(int argc, char **argv, char **envp)
{
    env_t *env = my_get_env(NULL, envp);
    char *buf = NULL;
    char **commands;

    if (argc > 1) {
        mini_printf("%s : Command not found.\n", argv[1]);
        return 84;
    }
    while (get_input(&buf), buf != NULL) {
        if (buf[0] == '\0')
            continue;
        commands = parse_command(buf);
        for (int i = 0; commands[i] != NULL; i++)
            process_and_handle_command(&env, commands[i]);
        free(commands);
    }
    free_all(env);
    free(env);
    return 0;
}
