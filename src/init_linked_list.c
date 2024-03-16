/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** init_linked_list
*/

#include "../include/struct.h"
#include "../include/proto.h"
#include "../include/minishell.h"

env_t *create_env_node(char **envp, char *key, char *content)
{
    env_t *env_node = malloc(sizeof(*env_node));

    if (env_node == NULL) {
        return NULL;
    }
    env_node->envp = envp;
    env_node->key = key;
    env_node->content = content;
    env_node->next = NULL;
    return (env_node);
}

void add_new_elem(env_t **head, env_t *new_elem)
{
    env_t *current_elem;

    if (*head == NULL) {
        *head = new_elem;
    } else {
        current_elem = *head;
        while (current_elem->next != NULL) {
            current_elem = current_elem->next;
        }
        current_elem->next = new_elem;
    }
}

void delete_env_node(env_t **head, env_t *node_to_delete)
{
    env_t *current_node;

    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        current_node = *head;
        while (current_node != NULL && current_node->next != node_to_delete) {
            current_node = current_node->next;
        }
        if (current_node != NULL) {
            current_node->next = node_to_delete->next;
        }
    }
    free(node_to_delete);
}

env_t *find_env_node(env_t *head, const char *key)
{
    env_t *current_elem = head;

    while (current_elem != NULL && my_strcmp(current_elem->key, key) != 0) {
        current_elem = current_elem->next;
    }
    return current_elem;
}
