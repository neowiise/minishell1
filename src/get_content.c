/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** get_content
*/

#include "../include/minishell.h"
#include "../include/proto.h"
#include "../include/struct.h"
#include "../lib/mini_printf.h"

char *get_content(env_t *env, char *key)
{
    env_t *cpy = env;

    while (cpy != NULL) {
        cpy = cpy->next;
        if (cpy && cpy->key && my_strcmp(cpy->key, key) == 0)
            return my_strdup(cpy->content);
    }
    return NULL;
}

env_t *my_get_env(env_t *env, char **envp)
{
    char **display = NULL;
    env_t *new_elem;

    for (int i = 0; envp[i] != NULL; i++) {
        display = my_str_to_word_array(envp[i], "=");
        new_elem = create_env_node(envp, display[0], display[1]);
        add_new_elem(&env, new_elem);
    }
    return (env);
}

char *find_path(env_t *env)
{
    env_t *current = env;

    while (current != NULL) {
        if (my_strcmp(current->key, "PATH") == 0) {
            return current->content;
        }
        current = current->next;
    }
    return NULL;
}

void print_env_list(env_t **env_list)
{
    for (env_t *tmp = *env_list; tmp != NULL; tmp = tmp->next) {
        if (tmp->content != NULL) {
            mini_printf("%s=%s\n", tmp->key, tmp->content);
        } else {
            mini_printf("%s=\n", tmp->key);
        }
    }
}
