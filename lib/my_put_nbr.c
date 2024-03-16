/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** my_putnbr
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / i) >= 10) {
            i *= 10;
        }
        while (i > 0) {
            my_putchar((nb / i) % 10 + '0');
            i /= 10;
        }
    }
    return 0;
}
