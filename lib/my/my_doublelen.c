/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** my_doublelen
*/

#include "my.h"

int my_doublelen(double nb)
{
    int len = (nb < 0) + 1;
    nb = round_double(nb, 6) * (nb < 0 ? -1 : 1);
    long ent = nb;
    long dec = nb * (float)1000000;
    dec -= ent * 1000000;

    while (ent) {
        ent /= 10;
        len++;
    }
    if (dec > 922337203685477589 || dec < -922337203685477589)
        dec = 0;

    for (len += 6 - my_longlen(dec); dec; dec /= 10, len++);

    while (dec) {
        dec /= 10;
        len++;
    }
    return (len);
}

int my_doublelen_nt(double nb)
{
    int len = (nb < 0) + 1;
    nb = round_double(nb, 3) * (nb < 0 ? -1 : 1);
    long ent = nb;
    long multiplier = my_pow(10, 6 - my_longlen(ent));
    long dec = nb * (float)multiplier;
    dec -= ent * multiplier;
    while (ent) {
        ent /= 10;
        len++;
    }
    if (dec > 922337203685477589 || dec < -922337203685477589) dec = 0;
    if (dec == 0) return (len - 1);

    for (len += 6 - my_longlen(dec); dec; dec /= 10, len++);
    while (dec) {
        dec /= 10;
        len++;
    }
    return (len);
}
