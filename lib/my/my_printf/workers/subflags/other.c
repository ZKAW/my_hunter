/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** space subflag handling
*/

#include <stddef.h>
#include "../../../my.h"
#include "../../include/my_printf.h"
#include "../../include/flags.h"
#include "../../include/handlers.h"

int threat_nothing(va_list arg, char const *format, int *index, int len)
{
    *index = *index - 1;
    *va_arg(arg, int *) = len;
    return (0);
}
