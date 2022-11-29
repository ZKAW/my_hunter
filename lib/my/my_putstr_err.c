/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** disp string char one by one
*/

#include <unistd.h>

int my_putstr_err(char const *str)
{
    for (int i = 0; str[i]; i++) {
        write(2, &str[i], 1);
    }
}
