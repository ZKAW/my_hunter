/*
** EPITECH PROJECT, 2022
** unsigned.c
** File description:
** unsigned int handling
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../../my.h"

int threat_unsign_int(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);
    my_put_nbr_unsigned(nb);
    return (my_intlen_unsigned(nb));
}
