/*
** EPITECH PROJECT, 2022
** my_evil_str.c
** File description:
** reverse string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int str_length = my_strlen(str) - 1;
    char tmp_chr;

    while (i <= str_length / 2) {
        tmp_chr = str[i];
        str[i] = str[str_length - i];
        str[str_length - i] = tmp_chr;
        i++;
    }

    return str;
}
