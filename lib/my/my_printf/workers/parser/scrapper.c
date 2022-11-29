/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** scrapper
*/

#include "../../../my.h"
#include "../../include/my_printf.h"
#include "../../include/flags.h"
#include "../../include/handlers.h"

#include <unistd.h>
#include <stdio.h>

int get_base_prefix_len(char c)
{
    if (c == 'x' || c == 'X') return (2);
    if (c == 'o') return (1);
    return (0);
}

char get_format_flag(char const *format, int *index)
{
    for (int i = 0; FLAGS_FORMAT[i]; i ++) {
        if (FLAGS_FORMAT[i] == format[*index]) {
            *index += 1;
            return (format[*index - 1]);
        }
    }
    return ('\0');
}

char get_specifier(char const *format, int *index)
{
    for (int i = 0; SPECIFIERS[i]; i ++) {
        if (SPECIFIERS[i] == format[*index]) {
            return (format[*index]);
        }
    }
    return ('\0');
}

int get_width_modifier(va_list arg, char const *format, int *index)
{
    va_list arg_copy;
    va_copy(arg_copy, arg);
    int width = 0;

    if (format[*index] == '*') {
        *index += 1;
        return (va_arg(arg_copy, int));
    }
    for (; format[*index] >= '0' && format[*index] <= '9'; *index += 1) {
        width = width * 10 + (format[*index] - '0');
    }

    return (width);
}

int get_specifier_length(va_list arg, char const *format, int *index)
{
    char flag = format[*index];

    for (int i = 0; SPECIFIERS[i]; i ++) {
        if (SPECIFIERS[i] == flag) {
            return (specifier_length[i](arg));
        }
    }
}
