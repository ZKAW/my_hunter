/*
** EPITECH PROJECT, 2022
** my_put_hexa.c
** File description:
** put hexa
*/

#include "my.h"

void my_put_hexa(unsigned int nb)
{
    char *str = my_itoa_base_unsigned(nb, "0123456789abcdef", 0);
    my_putstr(str);
}

void my_put_hexa_long(unsigned long nb)
{
    char *str = my_itoa_base_unsigned_long(nb, "0123456789abcdef", 0);
    my_putstr(str);
}
