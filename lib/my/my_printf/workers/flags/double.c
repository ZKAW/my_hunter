/*
** EPITECH PROJECT, 2022
** double.c
** File description:
** double handling
*/

#include <stddef.h>
#include "../../../my.h"
#include "../../include/my_printf.h"

int threat_scientific_double(va_list arg)
{
    double nb = va_arg(arg, double);
    my_put_scientific_double(nb, 0, 6);
    return (12 + (nb < 0));
}

int threat_scientific_double_maj(va_list arg)
{
    double nb = va_arg(arg, double);
    my_put_scientific_double(nb, 1, 6);
    return (12 + (nb < 0));
}

int threat_decimal_double(va_list arg)
{
    double nb = va_arg(arg, double);
    my_put_double(nb, 6);
    return (my_doublelen(nb));
}

int threat_shorter_double(va_list arg)
{
    double nb = va_arg(arg, double);
    int dec_len = my_doublelen_nt(nb);
    int scientific_len = my_doublelen(nb);

    if (dec_len < scientific_len) {
        my_put_double_nt(nb);
        return (dec_len);
    } else {
        my_put_scientific_double(nb, 0, 5);
        return (12 + (nb < 0));
    }
}

int threat_shorter_double_maj(va_list arg)
{
    double nb = va_arg(arg, double);
    int dec_len = my_doublelen_nt(nb);
    int scientific_len = my_doublelen(nb);

    if (dec_len < scientific_len) {
        my_put_double_nt(nb);
        return (dec_len);
    } else {
        my_put_scientific_double(nb, 1, 5);
        return (12 + (nb < 0));
    }
}
