/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../include/proto.h"
#include "../include/struct.h"
#include "../include/minishell.h"

void free_word_array(char **word_array)
{
    if (word_array) {
        for (int i = 0; word_array[i] != NULL; ++i) {
            free(word_array[i]);
        }
        free(word_array);
    }
}

char *extract_word(char const *s, int start, size_t word_len)
{
    char *word = malloc(sizeof(char) * (word_len + 1));

    if (!word)
        return NULL;
    for (int i = 0; i < word_len; ++i) {
        word[i] = s[start + i];
    }
    word[word_len] = '\0';
    return word;
}

void process_string(const char *s, char const *delim, char **word_array)
{
    int i = 0;
    int word_index = 0;
    int word_length;
    char *word;

    while (s[i] != '\0') {
        i = skip_delimiters(s, delim, i);
        word_length = calculate_word_length(s, delim, i);
        word = extract_word(s, i, word_length);
        if (!word) {
            free_word_array(word_array);
            return;
        }
        word_array[word_index] = word;
        word_index++;
        i += word_length;
    }
    word_array[word_index] = NULL;
}

char **my_str_to_word_array(char const *s, char const *delim)
{
    int num_words;
    char **word_array;

    if (!s)
        return NULL;
    num_words = count_words(s, delim);
    word_array = allocate_memory(num_words);
    if (!word_array)
        return NULL;
    process_string(s, delim, word_array);
    return word_array;
}
