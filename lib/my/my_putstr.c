/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** disp string char one by one
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}
