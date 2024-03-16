/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-iness.el-atouani
** File description:
** str_to2
*/

#include "../include/proto.h"
#include "../include/struct.h"
#include "../include/minishell.h"

int detect(char const c, char const *delim)
{
    int i = 0;

    while (delim[i] != '\0') {
        if (c == delim[i])
            return 1;
        ++i;
    }
    return 0;
}

int count_words(char const *s, char const *delim)
{
    int words = 0;
    int i = 0;

    while (s[i] != '\0'){
        if (detect(s[i], delim) == 1 && detect(s[i + 1], delim) == 0)
            ++words;
        ++i;
    }
    return words + 1;
}

char **allocate_memory(int num_words)
{
    return malloc(sizeof(char *) * (num_words + 1));
}

int skip_delimiters(char const *s, char const *delim, int i)
{
    while (detect(s[i], delim) == 1 && s[i] != '\0')
        ++i;
    return i;
}

int calculate_word_length(char const *s, char const *delim, int i)
{
    int length = 0;

    while (detect(s[i], delim) == 0 && s[i] != '\0') {
        ++i;
        ++length;
    }
    return length;
}
