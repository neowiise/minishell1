/*
** EPITECH PROJECT, 2023
** handling
** File description:
** handlings
*/

#include "mini_printf.h"
#include "my.h"
#include "../include/proto.h"

int handle_char(va_list args)
{
    return my_putchar(va_arg(args, int));
}

int handle_int(va_list args)
{
    return my_put_nbr(va_arg(args, int));
}

int handle_string(va_list args)
{
    return my_putstr(va_arg(args, const char *));
}

int handle_percent(va_list args)
{
    (void)args;
    return my_putchar('%');
}
