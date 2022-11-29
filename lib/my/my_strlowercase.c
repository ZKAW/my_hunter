/*
** EPITECH PROJECT, 2022
** my_strlowercase.c
** File description:
** lower case str
*/

#include "my.h"

char *my_strlowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            continue;
        }
        str[i] += 32;
    }

    return (str);
}
