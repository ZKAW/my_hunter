/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** textures
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/myhunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

int get_texture_width(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);

    return (size.x);
}

int get_texture_height(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);

    return (size.y);
}

sfSprite *create_background(void)
{
    sfTexture *texture = sfTexture_createFromFile(BACKGROUND_P, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f) {1.6, 1.5});
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
