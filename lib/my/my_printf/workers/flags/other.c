/*
** EPITECH PROJECT, 2022
** other.c
** File description:
** other handling
*/

#include <stddef.h>
#include "../../../my.h"
#include "../../include/my_printf.h"

int threat_ipvar(va_list arg)
{
    int len = 2;
    void *ptr = va_arg(arg, void *);
    unsigned long nb = (unsigned long) ptr;

    my_putstr("0x");
    my_put_hexa_long(nb);

    while (nb > 0) {
        nb /= 16;
        len++;
    }

    return (len);
}

int threat_modulo(va_list arg)
{
    my_putchar('%');

    return (1);
}

int return_one(va_list arg)
{
    return (1);
}
