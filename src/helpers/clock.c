/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** clock
*/

#include "../../include/myhunter.h"

float get_time(sfClock *clock)
{
    return (sfTime_asSeconds(sfClock_getElapsedTime(clock)));
}
