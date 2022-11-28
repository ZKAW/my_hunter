/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** textures
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/bsmyhunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

int get_texture_width(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);

    return (size.x - 1);
}

int get_texture_height(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);

    return (size.y - 1);
}
