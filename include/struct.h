/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #define MAX_ARGS 100
    #define MAX_COMMANDS 10

typedef struct env_s {
    char **envp;
    char *key;
    char *content;
    // char *pwd;
    struct env_s *next;
} env_t;

typedef struct redirection_s {
    int left;
    int right;
    int redi_right;
    int redi_left;
} redirection_t;

#endif /* !STRUCT_H_ */
