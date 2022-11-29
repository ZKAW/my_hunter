/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** get_length2
*/

#include "../include/my_printf.h"
#include "../../my.h"

int get_str_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    char *str = va_arg(arg_copy, char *);

    return (my_strlen(str));
}

int get_scientific_double_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    double nb = va_arg(arg_copy, double);

    return (12 + (nb < 0));
}

int get_decimal_double_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    double nb = va_arg(arg_copy, double);

    return (my_doublelen(nb));
}

int get_ipvar_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    int len = 2;
    void *ptr = va_arg(arg_copy, void *);
    unsigned long nb = (unsigned long )ptr;

    while (nb > 0) {
        nb /= 16;
        len++;
    }

    return (len);
}

int get_shorter_double_len(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);

    double nb = va_arg(arg_copy, double);
    int dec_len = my_doublelen_nt(nb);
    int scientific_len = my_doublelen(nb);

    return (dec_len < scientific_len ? dec_len : scientific_len);
}
