/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** raise nb to the power of n recursively
*/

int my_pow(int nb, int p)
{
    int res = 1;

    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p == 1) {
        return (nb);
    }

    return (nb * (my_pow(nb, p - 1)));
}
