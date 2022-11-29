/*
** EPITECH PROJECT, 2022
** myls
** File description:
** my_tablen
*/

#include <unistd.h>

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}
