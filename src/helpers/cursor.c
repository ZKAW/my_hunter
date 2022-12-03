/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** cursor
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

sfSprite *create_cursor(void)
{
    sfTexture *texture = sfTexture_createFromFile(CURSOR_P, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void display_cursor(game_t *game)
{
    if (game->scene != 1) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        return;
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse_pos.x - 95, mouse_pos.y - 100};
    sfSprite_setPosition(game->cursor, pos);
    sfRenderWindow_drawSprite(game->window, game->cursor, NULL);
}
