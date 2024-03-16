/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** get_input
*/

#include "../include/minishell.h"
#include "../include/proto.h"
#include "../include/struct.h"

void get_input(char **buf)
{
    int bufsize = 0;
    int read;
    int len;

    if (isatty(0) != 0) {
        write(1, "$> ", 3);
    }
    read = getline(buf, &bufsize, stdin);
    if (read == -1) {
        free(*buf);
        *buf = NULL;
        return;
    }
    len = my_strlen(*buf);
    if ((*buf)[len - 1] == '\n') {
        (*buf)[len - 1] = '\0';
    }
}
