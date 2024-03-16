/*
** EPITECH PROJECT, 2022
** task
** File description:
** my_strcmp
*/

#include "../include/proto.h"
#include "../include/minishell.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
