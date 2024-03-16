/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-iness.el-atouani
** File description:
** error_env
*/

#include "../include/minishell.h"
#include "../include/proto.h"
#include "../include/struct.h"
#include "../lib/mini_printf.h"

int isalpha(char ch)
{
    if ((ch >= '0' & ch <= '9') ||
        (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

int error_env(char *str)
{
    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')) {
        return (0);
    }
    my_putstr("setenv: Variable name must begin with a letter.\n");
    return (-1);
}

int is_valid_variable_name(char *name)
{
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            mini_printf("setenv: Variable name must contain alphanumerics.\n");
            return 0;
        }
    }
    return 1;
}
