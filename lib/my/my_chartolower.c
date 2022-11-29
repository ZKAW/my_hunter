/*
** EPITECH PROJECT, 2022
** myls
** File description:
** my_chartolower
*/

char my_chartolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
