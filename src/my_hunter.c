/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** my_hunter
*/

#include "../include/bsmyhunter.h"
#include <stdio.h>
#include <stdlib.h>

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

float get_time(sfClock *clock) {
    return (sfTime_asSeconds(sfClock_getElapsedTime(clock)));
}

sprite_t *create_sprite(char *path, int size, float anim_speed, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->width = get_texture_width(sprite->texture);
    sprite->height = get_texture_height(sprite->texture);
    sprite->rect = create_rect(0, 0, sprite->width, sprite->height);
    sprite->pos = pos;
    sprite->scale = (sfVector2f) {1, 1};
    sprite->origin = (sfVector2f) {0, 0};
    sprite->anim_speed = anim_speed;
    sprite->size = size;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setOrigin(sprite->sprite, sprite->origin);
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

int my_hunter(void)
{
    sfRenderWindow *window = create_window();
    sfClock *clock = sfClock_create();
    sfEvent event;
    sprite_t *pigeon = create_sprite("assets/pigeon.png", 110, 0.2, (sfVector2f) {110, 110});

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_sprite(window, pigeon, clock);
        while (sfRenderWindow_pollEvent(window, &event))
            // sprites
            analyse_events(window, event, pigeon->sprite);
        sfRenderWindow_display(window);
    }
    close_window(window);
    return (0);
}
