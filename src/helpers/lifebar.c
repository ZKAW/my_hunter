/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** lives
*/

#include "../../include/myhunter.h"

void update_lifebar(game_t *game, int lives)
{
    sfIntRect rect = sfSprite_getTextureRect(game->life_bar);
    rect.width = lives * 10;
    sfSprite_setTextureRect(game->life_bar, rect);
}
