/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return (dest);
}
