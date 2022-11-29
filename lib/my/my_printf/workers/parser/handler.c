/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** parser of the format string,
** it will parse the format string and call the right handler for each flag
** %[flags][width]specifier
*/

#include "../../../my.h"
#include "../../include/my_printf.h"
#include "../../include/flags.h"
#include "../../include/handlers.h"
#include <unistd.h>
#include <stdio.h>

int handle_format_flags(va_list arg, char const *format, int flag_i, int gap)
{
    int len = 0;

    for (int i = 0; FLAGS_FORMAT[i]; i ++) {
        if (FLAGS_FORMAT[i] == format[flag_i]) {
            flags_format_handlers[i](arg, format, flag_i + gap);
        }
    }

    return (len);
}

int handle_width(va_list arg, char const *format, int *index, int width)
{
    int len = 0;
    int flag_i = *index - (my_intlen(width)) - 1;
    char specifier = get_specifier(format, index);
    va_list arg_copy;
    va_copy(arg_copy, arg);
    width -= get_specifier_length(arg, format, index);
    if (format[flag_i] == '#') width -= get_base_prefix_len(specifier);
    if (format[flag_i] == '-') {
        int nb = va_arg(arg_copy, int);
        if ((specifier == 'd' || specifier == 'i') && nb >= 0) width -= 1;
    }
    for (int i = 0; i < width; i ++) {
        if (format[flag_i] == '0')
            my_putchar('0');
        else
            my_putchar(' ');
        len ++;
    }
    len += handle_format_flags(arg, format, flag_i, *index - flag_i);
    return (len);
}

int handle_specifier(va_list arg, char const *format, int *index, int len)
{
    char flag = format[*index];

    for (int j = 0; SPECIFIERS[j]; j ++) {
        if (flag == 'n') {
            *va_arg(arg, int *) = len;
            return (0);
        }
        if (SPECIFIERS[j] == flag) {
            return (specifier_handlers[j](arg));
        }
    }

    return (0);
}

int handle_flags(va_list arg, char const *format, int *index, int len)
{
    int tmp_len = 0;
    char format_flag = get_format_flag(format, index);
    int width = get_width_modifier(arg, format, index);
    if (check_specifier(format[*index]) == 84) return (-84);
    char specifier = get_specifier(format, index);

    if (format_flag == '-') {
        va_list arg_copy;
        va_copy(arg_copy, arg);
        tmp_len += handle_specifier(arg_copy, format, index, len + tmp_len);
    }

    if (width > 0)
        tmp_len += handle_width(arg, format, index, width);
    else
        tmp_len += handle_format_flags(arg, format, *index - 1, 1);
    if (format_flag != '-')
        tmp_len += handle_specifier(arg, format, index, len + tmp_len);

    return (tmp_len);
}
