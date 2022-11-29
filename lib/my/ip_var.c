/*
** EPITECH PROJECT, 2022
** ip_var
** File description:
** Disp ip
*/

#include "my.h"

void ip_var(void* arg)
{
    my_putstr("0x");
    my_put_hexa_long((unsigned long) arg);
}
