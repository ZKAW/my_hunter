/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** is_nbr_positive
*/

#include "../include/my_printf.h"

int is_int_positive(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    int nb = va_arg(arg_copy, int);

    if (nb >= 0)
        return (1);
    return (0);
}

int is_double_positive(va_list arg)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    double nb = va_arg(arg_copy, double);

    if (nb >= 0)
        return (1);
    return (0);
}
