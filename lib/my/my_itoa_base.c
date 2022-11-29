/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** convert integer to specified base and return it as a string
*/

#include <stdlib.h>
#include "my.h"

char *my_itoa_base(int nbr, char const *base, int i)
{
    int len = my_strlen(base);
    char *str = malloc(sizeof(char) * 100);

    if (nbr < 0) {
        str[i] = '-';
        i++;
        nbr = -nbr;
    }
    if (nbr >= len)
        my_itoa_base(nbr / len, base, i + 1);
    str[i] = base[nbr % len];

    return (my_revstr(str));
}

char *my_itoa_base_unsigned(unsigned int nbr, char const *base, int i)
{
    int len = my_strlen(base);
    char *str = malloc(sizeof(char) * 100);
    str[i + 1] = '\0';

    if (nbr >= (unsigned int)len)
        str = my_itoa_base_unsigned(nbr / len, base, i + 1);
    str[i] = base[nbr % len];

    return (my_revstr(str));
}

char *my_itoa_base_unsigned_long(unsigned long nbr, char const *base, int i)
{
    int len = my_strlen(base);
    char *str = malloc(sizeof(char) * 100);
    str[i + 1] = '\0';

    if (nbr >= (unsigned long)len)
        str = my_itoa_base_unsigned_long(nbr / len, base, i + 1);
    str[i] = base[nbr % len];

    return (my_revstr(str));
}
