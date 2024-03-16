/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** handle_cd
*/

#include "../include/proto.h"
#include "../include/minishell.h"
#include "../include/struct.h"
#include "../lib/mini_printf.h"
#include <sys/types.h>
#include <sys/stat.h>

static int classic_cd(char *str)
{
    if (chdir(str) != 0) {
        mini_printf("Not a directory.\n", str);
        return 1;
    }
    return (0);
}

static void my_cd_previous(char *prev_dir)
{
    if (!prev_dir || prev_dir[0] == '\0') {
        mini_printf("cd: OLDPWD not set\n");
        return;
    }
    chdir(prev_dir);
}

int handle_no_argument(env_t **env, char *prev_dir)
{
    char *home = get_content(*env, "HOME");
    char current_dir[10000];
    char new_dir[10000];

    getcwd(current_dir, 10000);
    if (home == NULL) {
        mini_printf("cd: HOME not set\n");
        return 1;
    }
    chdir(home);
    free(home);
    my_set_env(env, "OLDPWD", current_dir);
    getcwd(new_dir, 10000);
    my_set_env(env, "PWD", new_dir);
    return 0;
}

int my_cd(env_t **env, char **argv)
{
    char *prev_dir = get_content(*env, "OLDPWD");
    char current_dir[10000];
    char new_dir[10000];

    getcwd(current_dir, 10000);
    if (argv[1] == NULL) {
        return handle_no_argument(env, prev_dir);
    } else if (my_strcmp(argv[1], "-") == 0) {
        my_cd_previous(prev_dir);
    } else {
        classic_cd(argv[1]);
    }
    my_set_env(env, "OLDPWD", current_dir);
    getcwd(new_dir, 10000);
    my_set_env(env, "PWD", new_dir);
    return 0;
}
