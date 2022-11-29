/*
** EPITECH PROJECT, 2022
** my_sqrt.c
** File description:
** returns the square root of nb
*/

int my_sqrt(int nb)
{
    for (int i = 0; i * i <= nb; ++i) {
        if (i * i == nb) {
            return (i);
        }
    }

    return (0);
}
