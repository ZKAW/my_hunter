/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** Disp float
*/

int my_putchar(char c);
int my_put_nbr(int nb);

void my_put_float(float res)
{
    int nbr = (int)(res * 100);

    my_put_nbr(nbr / 100);
    my_putchar('.');
    my_putchar(((nbr / 10) % 10) + 48);
    my_putchar((nbr % 10) + 48);
}
