/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** extract number from string
*/

int is_char_digit(char chr)
{
    if ((chr >= 48) && (chr <= 57)) {
        return (1);
    } else {
        return (0);
    }
}

int is_str_neg(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] == '-') && is_char_digit(str[i + 1])) {
            return (1);
        }
    }

    return (0);
}

int is_nbr_in_str(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (is_char_digit(str[i])) {
            return (1);
        }
    }

    return (0);
}

int my_getnbr(char *str)
{
    long nbr = 0;
    int i = 0;

    if (!is_nbr_in_str(str)) {
        return (0);
    }
    for (i = 0; str[i]; i++) {
        if (is_char_digit(str[i])) {
            break;
        }
    }

    for (i; is_char_digit(str[i]); i++) {
        nbr = (nbr * 10) + (str[i] - 48);
    }
    if (nbr > 2147483647) {
        return (0);
    }

    return nbr * (is_str_neg(str) ? -1 : 1);
}
