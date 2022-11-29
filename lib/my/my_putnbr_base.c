/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** putnbr base (convert integer to specified base)
*/

#include "my.h"

int my_putnbr_base_unsigned(unsigned int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr >= (unsigned int)len)
        my_putnbr_base_unsigned(nbr / len, base);
    my_putchar(base[nbr % len]);
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr >= len)
        my_putnbr_base(nbr / len, base);
    my_putchar(base[nbr % len]);
    return (0);
}

int my_putnbr_base_long(long nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr >= (long)len)
        my_putnbr_base_long(nbr / len, base);
    my_putchar(base[nbr % len]);
    return (0);
}
