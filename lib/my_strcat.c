/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcat
*/

#include "../include/minishell.h"
#include "../include/proto.h"

char *my_strcat(char *dest, const char *src)
{
    char *p = dest + my_strlen(dest);

    while (*src != '\0') {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return dest;
}
