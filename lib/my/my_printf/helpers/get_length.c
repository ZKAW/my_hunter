/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** get_length
*/

#include "../include/my_printf.h"
#include "../../my.h"

int get_int_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    int nb = va_arg(arg_copy, int);

    return (my_intlen(nb));
}

int get_unsigned_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    unsigned int nb = va_arg(arg_copy, unsigned int);

    return (my_intlen_unsigned(nb));
}

int get_octal_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    int nb = va_arg(arg_copy, int);
    int len = 0;

    while (nb > 0) {
        nb /= 8;
        len++;
    }

    return (len);
}

int get_hex_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    int nb = va_arg(arg_copy, int);
    int len = 0;

    while (nb > 0) {
        nb /= 16;
        len++;
    }

    return (len);
}

int get_bin_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    int nb = va_arg(arg_copy, int);
    int len = 0;

    while (nb > 0) {
        nb /= 2;
        len++;
    }

    return (len);
}
