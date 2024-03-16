/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** env_set_unset
*/

#include "../include/minishell.h"
#include "../include/proto.h"
#include "../include/struct.h"
#include "../lib/mini_printf.h"

extern char **environ;

void my_set_env(env_t **env_list, char *name, char *value)
{
    env_t *current_elem = *env_list;

    if (name == NULL && value == NULL) {
        print_env_list(env_list);
        return;
    }
    while (current_elem != NULL) {
        if (my_strcmp(current_elem->key, name) == 0) {
            current_elem->content = my_strdup(value);
            return;
        }
        current_elem = current_elem->next;
    }
    set_env_sec(env_list, name, value);
}

void set_env_sec(env_t **env_list, char *name, char *value)
{
    env_t *current_elem = *env_list;
    char **envp = environ;
    env_t *new_elem = create_env_node(envp, name, value);

    if (new_elem == NULL) {
        mini_printf("too few arguments\n");
        return;
    }
    if (*env_list == NULL) {
        *env_list = new_elem;
    } else {
        current_elem = *env_list;
        while (current_elem->next != NULL) {
            current_elem = current_elem->next;
        }
        current_elem->next = new_elem;
    }
}

env_t *find_env_node_var(env_t *env_list, char *name)
{
    env_t *current_elem = env_list;

    while (current_elem != NULL) {
        if (my_strcmp(current_elem->key, name) == 0) {
            return current_elem;
        }
        current_elem = current_elem->next;
    }
    return NULL;
}

void remove_env_node(env_t **env_list, env_t *node)
{
    while (*env_list && *env_list != node) {
        env_list = &(*env_list)->next;
    }
    if (*env_list == node) {
        *env_list = node->next;
        delete_env_node(env_list, node);
    }
}

void my_unset_env(env_t **env_list, char *name)
{
    env_t *node = find_env_node_var(*env_list, name);

    if (node != NULL) {
        remove_env_node(env_list, node);
    }
}
