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

int threat_space(va_list arg, char const *format, int index)
{
    char next_flag = format[index];
    for (int i = 0; SPECIFIERS_NUM[i]; i ++) {
        if ((SPECIFIERS_NUM[i] == next_flag) && (positive_table[i](arg))) {
            my_putchar(' ');
            return (1);
        }
    }
    return (0);
}

int threat_positive(va_list arg, char const *format, int index)
{
    char next_flag = format[index];
    for (int i = 0; SPECIFIERS_NUM[i]; i ++) {
        if ((SPECIFIERS_NUM[i] == next_flag) && (positive_table[i](arg))) {
            my_putchar('+');
            return (1);
        }
    }
    return (0);
}

int threat_hashtag(va_list arg, char const *format, int index)
{
    char next_flag = format[index];
    for (int i = 0; SPECIFIERS_BASE[i]; i ++) {
        if ((SPECIFIERS_BASE[i] == next_flag)) {
            int jump = base_prefix[i](arg);
            return (jump);
        }
    }
    return (0);
}
