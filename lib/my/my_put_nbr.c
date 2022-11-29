/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Disp integer
*/

int my_putchar(char c);

int my_put_nbr(int nb)
{
    long nbc = (long)nb;

    if (nbc < 0) {
        my_putchar('-');
        nbc *= -1;
    }

    int val = nbc / 10;

    if (val > 0) {
        my_put_nbr(val);
    }

    char c = nbc % 10 + '0';

    my_putchar(c);

    return (0);
}

int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb >= 10)
        my_put_nbr_unsigned(nb / 10);

    my_putchar(nb % 10 + '0');

    return (0);
}

int my_put_nbr_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }

    int val = nb / 10;

    if (val > 0) {
        my_put_nbr_long(val);
    }

    char c = nb % 10 + '0';

    my_putchar(c);

    return (0);
}
