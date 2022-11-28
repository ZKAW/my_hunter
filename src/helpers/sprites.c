/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** sprites
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/bsmyhunter.h"

sprite_t *create_sprite(char *path, int nb_s, float anim_speed, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->width = get_texture_width(sprite->texture);
    sprite->height = get_texture_height(sprite->texture);
    sprite->size = sprite->width / nb_s;
    sprite->rect = (sfIntRect) {0, 0, sprite->size, sprite->height};
    sprite->pos = pos;
    sprite->scale = (sfVector2f) {1, 1};
    sprite->origin = (sfVector2f) {0, 0};
    sprite->anim_speed = anim_speed;

    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return (sprite);
}

void display_sprite(sfRenderWindow *window, sprite_t *sprite, sfClock *clock)
{
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
    float time_s = get_time(clock);
    if ((time_s - sprite->elasped_time) > sprite->anim_speed) {
        move_rect(&sprite->rect, sprite->size, sprite->width);
        sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        sprite->elasped_time = time_s;
    }
}
