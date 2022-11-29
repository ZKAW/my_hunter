/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copy n character into another string
*/

int my_strlen(char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n && src[i]; i++) {
        dest[i] = src[i];
    }

    if (n > my_strlen(dest)) {
        dest[i] = '\0';
    }

    return (dest);
}
