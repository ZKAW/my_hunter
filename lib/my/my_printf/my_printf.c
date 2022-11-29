/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_printf w/ flags
*/

#include <stdarg.h>
#include <unistd.h>
#include "../my.h"
#include "include/my_printf.h"
#include "include/flags.h"
#include "include/handlers.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    int len = 0;
    int res;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            len++;
            continue;
        }
        i++;
        res = handle_flags(ap, format, &i, len);
        if (res == -84) return (84);
        len += res;
    }
    va_end(ap);

    return (len);
}
