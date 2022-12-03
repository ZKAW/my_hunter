/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** display
*/

#include "../../include/myhunter.h"
#include "../../include/my.h"
#include <stdlib.h>

void display_text(game_t *game, char *str, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    sfVector2f position = pos;

    int len = my_strlen(str);
    if (len > 1) {
        pos.x -= (len * size) / 2;
    } else {
        pos.x -= size;
    }
    pos.y -= size;

    if (pos.x < 0) pos.x = position.x;
    if (pos.y < 0) pos.y = position.y;

    sfText_setString(text, str);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->window, text, NULL);
    free(text);
}

void display_score(game_t *game)
{
    int size = 30;

    my_itoa_dest(game->score_str, game->score);
    display_text(game, "Score: ", (sfVector2f) {50, 75}, size);
    display_text(game, game->score_str, (sfVector2f) {275, 75}, size);
}
