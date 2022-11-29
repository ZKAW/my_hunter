/*
** EPITECH PROJECT, 2022
** base.c
** File description:
** base handling
*/

#include <stdarg.h>
#include "../../../my.h"

int threat_bin(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *str = my_itoa_base_unsigned(nb, "01", 0);
    my_putstr(str);
    return (my_strlen(str));
}

int threat_octal(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *str = my_itoa_base_unsigned(nb, "01234567", 0);
    my_putstr(str);
    return (my_strlen(str));
}

int threat_hex(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *str = my_itoa_base_unsigned(nb, "0123456789abcdef", 0);
    my_putstr(str);
    return (my_strlen(str));
}

int threat_hex_maj(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    char *str = my_itoa_base_unsigned(nb, "0123456789ABCDEF", 0);
    my_putstr(str);
    return (my_strlen(str));
}
