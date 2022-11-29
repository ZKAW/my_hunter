/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare two strings
*/

#include <stdlib.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else if (s1[i] == '\0')
        return (-1);
    else
        return (1);
}

int my_strcmp_ci(const char *s1, const char *s2)
{
    if (s1[0] == '.') s1++;
    if (s2[0] == '.') s2++;
    char c1 = s1[0];
    char c2 = s2[0];

    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        c1 = s1[i];
        c2 = s2[i];
        c1 = (c1 >= 'A' && c1 <= 'Z') ? c1 + 32 : c1;
        c2 = (c2 >= 'A' && c2 <= 'Z') ? c2 + 32 : c2;
        if (c1 != c2) return (c1 - c2);
        i++;
    }

    return (s1[i] == '\0' ? -1 : 1);
}
