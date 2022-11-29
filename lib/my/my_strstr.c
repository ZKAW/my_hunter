/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** find str in str (get everything after specific str)
*/

#include <unistd.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    while (*str != '\0') {
        if (*str == *to_find) {
            return (str);
        }
        str++;
    }

    return (NULL);
}

char *my_strstr_from(char *str, char const *to_find, int from)
{
    int i = from;

    if (i >= my_strlen(str)) return (NULL);

    while (str[i] != '\0') {
        if (str[i] == to_find[0]) {
            return (&str[i]);
        }
        i++;
    }
}
