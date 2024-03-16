/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-bsminishell1-iness.el-atouani
** File description:
** my_strdup
*/

#include "../include/minishell.h"
#include "../include/proto.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str) + 1;
    char *new_str = (char *) malloc(len);

    if (new_str == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
