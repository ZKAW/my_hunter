/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main
*/

#include "../include/myhunter.h"
#include "../include/my.h"

void display_help(void)
{
    my_putstr("DESCRIPTION:\n");
    my_putstr("\tInspired by the famous \"Duck Hunt\" game.\n");
    my_putstr("\tYou have to shoot the evil");
    my_putstr(" Suk before they reach the paradise.\n");
    my_putstr("\tYou have 3 lives.\n");
    my_putstr("\tThe difficulty (speed and spawn rate) increases with time.\n");
    my_putstr("INPUT:\n");
    my_putstr("\tMove the crosshair with the mouse.\n");
    my_putstr("\tLeft click to shoot.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return (0);
    }
    return (my_hunter());
}
