/*
** EPITECH PROJECT, 2022
** my_round.c
** File description:
** round double
*/

#include "my.h"

double round_double(double nb, int precision)
{
    double tmp = 0;
    double tmp2 = 0;

    int is_neg = 0;
    if (nb < 0) {
        is_neg = 1;
        nb *= -1;
    }

    tmp = nb * my_pow(10, precision);
    tmp2 = tmp - (long)tmp;
    if (tmp2 >= 0.5)
        tmp += 1;

    tmp /= my_pow(10, precision);
    if (is_neg == 1)
        tmp *= -1;

    return (tmp);
}
