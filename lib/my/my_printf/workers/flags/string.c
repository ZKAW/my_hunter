/*
** EPITECH PROJECT, 2022
** string.c
** File description:
** string handling
*/

#include <stddef.h>
#include "../../../my.h"
#include "../../include/my_printf.h"

int threat_int(va_list arg)
{
    int nb = va_arg(arg, int);
    my_put_nbr(nb);
    return (my_intlen(nb));
}

int threat_char(va_list arg)
{
    my_putchar((char)va_arg(arg, int));
    return (1);
}

int threat_str(va_list arg)
{
    char *str = va_arg(arg, char *);
    my_putstr(str);
    return (my_strlen(str));
}
