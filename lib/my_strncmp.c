/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strncmp
*/


#include "../include/proto.h"
#include "../include/minishell.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0') {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
