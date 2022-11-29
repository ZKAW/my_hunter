/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** base_prefix
*/

#include "../include/my_printf.h"
#include "../../my.h"

int put_octal_prefix(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    int nb = va_arg(arg_copy, int);

    if (nb != 0) {
        my_putstr("0");
        return (1);
    }
    return (0);
}

int put_hex_prefix(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    int nb = va_arg(arg_copy, int);

    if (nb != 0) {
        my_putstr("0x");
        return (2);
    }
    return (0);
}

int put_hex_maj_prefix(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    int nb = va_arg(arg_copy, int);

    if (nb != 0) {
        my_putstr("0X");
        return (2);
    }
    return (0);
}
