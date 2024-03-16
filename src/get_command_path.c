/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** get_command_path
*/

#include "../include/struct.h"
#include "../include/minishell.h"
#include "../include/proto.h"
#include "../lib/mini_printf.h"

char **env_to_char_array_sec(env_t *env_list)
{
    int i = 0;
    int n = 0;
    env_t *current = env_list;
    char **tab = malloc(sizeof(char *) * (n + 1));
    char *tmp;

    current = env_list;
    while (current != NULL) {
        tmp = malloc(sizeof(char) * (my_strlen(current->key)
                    + my_strlen(current->content) + 2));
        my_strcat(tmp, current->key);
        my_strcat(tmp, "=");
        my_strcat(tmp, current->content);
        tab[i] = my_strdup(tmp);
        i++;
        current = current->next;
    }
    tab[i] = NULL;
    return tab;
}

char **env_to_char_array(env_t *env_list)
{
    int n = 0;
    env_t *current = env_list;

    while (current != NULL) {
        n++;
        current = current->next;
    }
    return (env_to_char_array_sec(env_list));
}

char *get_command_path_sec(char *command, char *path)
{
    char **splited = my_str_to_word_array(path, ":");
    char *tmp = NULL;
    struct stat buf;

    for (int i = 0; splited[i] != NULL; i++) {
        tmp = malloc(sizeof(char) * (my_strlen(splited[i])
                + my_strlen(command) + 2));
        my_strcat(tmp, splited[i]);
        my_strcat(tmp, "/");
        my_strcat(tmp, command);
        if (stat(tmp, &buf) == 0) {
            return (tmp);
        }
    }
    return NULL;
}

char *get_command_path(env_t *env, char *command)
{
    char *path = NULL;
    env_t *current = env;

    while (current != NULL) {
        if (my_strcmp("PATH", current->key) == 0){
                path = my_strdup(current->content);
                break;
            }
        current = current->next;
    }
    if (path == NULL) {
        write(2, "error: path not found\n", 23);
    }
    return (get_command_path_sec(command, path));
}
