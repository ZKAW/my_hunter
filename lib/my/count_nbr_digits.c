/*
** EPITECH PROJECT, 2022
** count_nbr_digits.c
** File description:
** count digits of nbr
*/

int count_nbr_digits(int nbr)
{
    int i = 0;

    if (nbr == 0)
        return (1);
    while (nbr != 0) {
        nbr /= 10;
        i++;
    }
    return (i);
}
