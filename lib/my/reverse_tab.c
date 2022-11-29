/*
** EPITECH PROJECT, 2022
** myls
** File description:
** reverse_tab
*/

#include "my.h"

char **reverse_tab(char **tab)
{
    char *tmp;

    for (int i = 0, j = my_tablen(tab) - 1; i < j; i++, j--) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }

    return (tab);
}
