/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** display double
*/

#include "my.h"

void my_put_double(double nb, int precision)
{
    nb = round_double(nb, precision);

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }

    long ent = nb;
    long multipler = my_pow(10, precision);
    long dec = nb * (float)multipler;
    dec -= ent * multipler;

    my_putnbr_base_long(ent, "0123456789");
    my_putchar('.');

    if (dec > 922337203685477589 || dec < -922337203685477589)
        dec = 0;
    for (int i = 0; i < precision - my_longlen(dec); i += 1)
        my_putchar('0');
    my_putnbr_base_long(dec, "0123456789");
}

void jveuxdormirwlh(long ent, long dec, int jade)
{
    for (int j = 0; j < (6 - my_longlen(ent)) - my_longlen(dec) - jade; j += 1)
    my_putchar('0');
    my_putnbr_base_long(dec, "0123456789");
}

void my_put_double_nt(double nb)
{
    nb = round_double(nb, 3);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    long ent = nb;
    long multiplier = my_pow(10, 6 - my_longlen(ent));
    long dec = nb * (float)multiplier;
    dec -= ent * multiplier;
    if (dec > 922337203685477589 || dec < -922337203685477589) dec = 0;
    my_putnbr_base_long(ent, "0123456789");
    if (dec == 0 || my_longlen(ent) > 6) return;
    my_putchar('.');
    int i = 0;
    while (dec % 10 == 0) {
        dec /= 10;
        i += 1;
    }
    jveuxdormirwlh(ent, dec, i);
}

void my_put_scientific_double(double nb, int is_maj, int precision)
{
    int i = 0;

    while (nb >= 10 || nb <= -10) {
        nb /= 10;
        i++;
    }
    my_put_double(nb, precision);

    is_maj ? my_putchar('E') : my_putchar('e');

    my_putchar('+');
    if (count_nbr_digits(i) < 2)
        my_putchar('0');
    my_put_nbr(i);
}
