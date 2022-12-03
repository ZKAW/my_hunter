/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** utils
*/

#include <stdlib.h>
#include "../../include/myhunter.h"

sfVector2f get_rand_spawn(void)
{
    int x;
    int y;

    y = rand() % 650 + 110;
    x = rand() % 200;

    return ((sfVector2f) {x, y});
}

int get_rand_int(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}

float get_rand_float(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * (max - min));
}

float deduce_anim_speed(float move_interval)
{
    float anim_speed = 1.0f / move_interval;
    if (anim_speed < 0.2f) anim_speed = 0.2f;
    return (anim_speed);
}
