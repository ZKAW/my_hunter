/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copy string in it
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *new_str = malloc(my_strlen(src) + 1);
    my_strcpy(new_str, src);

    return (new_str);
}
