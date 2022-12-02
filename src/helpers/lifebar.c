/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** lives
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

lifebar_t *create_lifebar(void)
{
    lifebar_t *lifebar = malloc(sizeof(lifebar_t));

    lifebar->texture = sfTexture_createFromFile(LIFE_BAR_P, NULL);
    lifebar->sprite = sfSprite_create();
    lifebar->width = get_texture_width(lifebar->texture);
    lifebar->height = get_texture_height(lifebar->texture);
    lifebar->size = lifebar->width / 3;
    lifebar->rect = (sfIntRect) {0, 0, lifebar->size, lifebar->height};
    sfSprite_setTexture(lifebar->sprite, lifebar->texture, sfTrue);
    sfSprite_setTextureRect(lifebar->sprite, lifebar->rect);
    sfSprite_setPosition(lifebar->sprite, (sfVector2f)
                        {SCREEN_WIDTH - (lifebar->size / 1.5), 20});
    sfSprite_setScale(lifebar->sprite, (sfVector2f) {0.5, 0.5});
    return (lifebar);
}

void update_lifebar(game_t *game, int lives)
{
    lifebar_t *lifebar = game->lifebar;
    sfIntRect rect = lifebar->rect;

    if (lives == 3) rect.left = 0;
    if (lives == 2) rect.left = lifebar->size;
    if (lives == 1) rect.left = lifebar->size * 2;
    if (lives == 0) rect.left = lifebar->size * 3;

    sfSprite_setTextureRect(lifebar->sprite, rect);
    sfRenderWindow_drawSprite(game->window, lifebar->sprite, NULL);
}
