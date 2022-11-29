/*
** EPITECH PROJECT, 2022
** errors.c
** File description:
** error handling for my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "../include/my_printf.h"
#include "../include/flags.h"
#include "../../my.h"

int is_specifier(char specifier)
{
    for (int i = 0; SPECIFIERS[i]; i ++) {
        if (SPECIFIERS[i] == specifier)
            return (1);
    }
    return (0);
}

int is_flag(char flag)
{
    for (int i = 0; FLAGS_FORMAT[i]; i ++) {
        if (FLAGS_FORMAT[i] == flag)
            return (1);
    }
    return (0);
}

int check_specifier(char specifier)
{
    if (!is_specifier(specifier)) {
        my_putstr_err("\nWarning: invalid identifier '");
        write(2, &specifier, 1);
        my_putstr_err("' in format string\n");
        return (84);
    }
    return (0);
}
