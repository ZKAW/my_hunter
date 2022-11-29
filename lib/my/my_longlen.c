/*
** EPITECH PROJECT, 2022
** get_long_len.c
** File description:
** get long length
*/

int my_longlen(long value)
{
    int len = value < 0 ? 1 : 0;

    if (value == 0)
        return (1);

    while (value) {
        len++;
        value = value / 10;
    }

    return len;
}
