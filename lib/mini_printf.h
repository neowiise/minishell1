/*
** EPITECH PROJECT, 2023
** struct
** File description:
** mini_printf
*/

#ifndef MINI_PRINTF_H_
    #define MINI_PRINTF_H_

    #include <stdarg.h>
typedef int (*format_handler)(va_list args);
struct flagf {
    char specifier;
    format_handler handler;
};

#endif /* !MINI_PRINTF_H_ */
