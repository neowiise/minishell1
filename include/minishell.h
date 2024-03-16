/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define _POSIX_SOURCE
    #define _POSIX_C_SOURCE 200809L
    #define _XOPEN_SOURCE 600
    #define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <sys/sysmacros.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <time.h>
    #include <grp.h>
    #include <errno.h>
    #include <sys/wait.h>

#endif /* !MINISHELL_H_ */
