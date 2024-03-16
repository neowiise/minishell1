/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include "struct.h"
    #include "../lib/mini_printf.h"
    #include "../lib/my.h"

void get_input(char **buf);
env_t *create_env_node(char **env, char *key, char *command);
int my_strcmp(char const *s1, char const *s2);
void print_env_list(env_t **env_list);
void add_new_elem(env_t **head, env_t *new_elem);
int handle_excve(env_t *env_list, char *command);
env_t *get_env(env_t *env, char **envp);
char **my_str_to_word_array(char const *s, char const *delim);
char *get_content(env_t *env, char *key);
int my_strlen(char const *str);
char *find_path(env_t *env);
void my_set_env(env_t **env_list, char *name, char *value);
void delete_env_node(env_t **head, env_t *node_to_delete);
void my_unset_env(env_t **env_list, char *name);
char *my_strdup(const char *str);
void set_env_sec(env_t **env_list, char *name, char *value);
int my_putstr(char const *str);
env_t *my_get_env(env_t *env, char **envp);
int my_putnbr(int n);
char *my_strcat(char *dest, const char *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_cd(env_t **env, char **argv);
char **parse_args(char *command);
int process_command(env_t **env, char *command);
int handle_env_command(env_t **env, char *command);
int handle_command(env_t **env, char *command);
char **parse_command(char *command);
char *get_command_path(env_t *env, char *command);
char *get_command_path_sec(char *command, char *path);
int execute_command(char *command_path, char **argv, char **envp);
char **env_to_char_array(env_t *env_list);
int token_command(char *command, char *delimiters,
    char **argv, int max_args);
void my_exit(char **str);
int mini_printf(const char *format, ...);
int my_putnbr(int n);
int detect(char const c, char const *delim);
int count_words(char const *s, char const *delim);
char **allocate_memory(int num_words);
int calculate_word_length(char const *s, char const *delim, int i);
int skip_delimiters(char const *s, char const *delim, int i);
int error_env(char *str);
int is_valid_variable_name(char *name);

#endif /* !PROTO_H_ */
