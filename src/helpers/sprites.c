/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** sprites
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/myhunter.h"
#include "../../include/my.h"

sprite_t *create_sprite(sfTexture *texture, int nb_frames,
                        float move_speed, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->sprite = sfSprite_create();
    sprite->texture = texture;
    sprite->width = get_texture_width(sprite->texture);
    sprite->height = get_texture_height(sprite->texture);
    sprite->size = sprite->width / nb_frames;
    sprite->rect = (sfIntRect) {0, 0, sprite->size, sprite->height};
    sprite->pos = pos;
    sprite->scale = (sfVector2f) {1, 1};
    sprite->origin = (sfVector2f) {0, 0};
    sprite->anim_speed = 0.2;
    sprite->move_speed = move_speed;

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
    sprite->pos.x += sprite->move_speed;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}

void display_sprites(linked_t *sprites, sfRenderWindow *window, sfClock *clock)
{
    while (sprites != NULL) {
        if (sprites->data->pos.y > -150)
            display_sprite(window, sprites->data, clock);
        sprites = sprites->next;
    }
}

void spawn_sprite(linked_t **sprites, sfVector2f pos, sfTexture *texture,
                float move_speed)
{
    sprite_t *sprite = create_sprite(texture, 3, move_speed, pos);
    add_in_linked(sprites, sprite);
}
