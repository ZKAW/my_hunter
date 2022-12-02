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
                        float move_interval, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->sprite = sfSprite_create();
    sprite->texture = texture;
    sprite->width = get_texture_width(sprite->texture);
    sprite->height = get_texture_height(sprite->texture);
    sprite->size = sprite->width / nb_frames;
    sprite->rect = (sfIntRect) {0, 0, sprite->size, sprite->height};
    sprite->pos = pos;
    sprite->scale = (sfVector2f) {1.3, 1.3};
    sprite->origin = (sfVector2f) {0, 0};
    sprite->move_interval = move_interval;
    sprite->anim_speed = deduce_anim_speed(move_interval);
    sprite->elapsed_time = 0;
    sprite->move_time = 0;

    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    return (sprite);
}

void display_sprite(sfRenderWindow *window, sprite_t *sprite, sfClock *clock)
{
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
    float time_s = get_time(clock);
    if ((time_s - sprite->elapsed_time) > sprite->anim_speed) {
        move_rect(&sprite->rect, sprite->size, sprite->width);
        sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        sprite->elapsed_time = time_s;
    }
}

void display_sprites(game_t *game)
{
    linked_t *tmp_sprites = game->sprites;
    while (tmp_sprites != NULL) {
        display_sprite(game->window, tmp_sprites->data, game->clock);
        tmp_sprites->data->pos.x += tmp_sprites->data->move_interval;
        sfSprite_setPosition(tmp_sprites->data->sprite,
                            tmp_sprites->data->pos);
        tmp_sprites = tmp_sprites->next;
    }
}

void spawn_sprites(game_t *game)
{
    float time_s = get_time(game->clock);
    float interval = get_rand_float(MIN_SPAWN_INTERVAL, MAX_SPAWN_INTERVAL);
    float speed = get_rand_float(MIN_SPEED, MAX_SPEED);
    if ((time_s - game->spawn_time) > interval) {
        sprite_t *sprite = create_sprite(game->suk, 2, speed, get_rand_spawn());
        add_in_linked(&game->sprites, sprite);
        game->spawn_time = time_s;
    }
}

void destroy_outside_sprites(game_t *game)
{
    linked_t *tmp_sprites = game->sprites;
    while (tmp_sprites != NULL) {
        if (tmp_sprites->data->pos.x > get_window_width(game->window)) {
            remove_from_linked(&game->sprites, tmp_sprites->data);
            game->lives--;
            tmp_sprites = game->sprites;
            continue;
        }
        tmp_sprites = tmp_sprites->next;
    }
}
