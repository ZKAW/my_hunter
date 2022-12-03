/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** base_events
*/

#include <stdio.h>
#include "../../include/myhunter.h"
#include "../../include/key_events.h"
#include "../../include/my.h"

void manage_mouse_click(game_t *game, sfMouseButtonEvent event)
{
    int x = event.x;
    int y = event.y;

    linked_t *tmp = game->sprites;
    while (tmp != NULL) {
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->data->sprite);
        if (sfFloatRect_contains(&rect, x, y)) {
            game->score++;
            set_highscore(game->score);
            remove_from_linked(&game->sprites, tmp->data);
            sfSound_play(game->sounds->suk_death);
            break;
        }
        tmp = tmp->next;
    }
}

void analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed && game->scene == 1)
        manage_mouse_click(game, event.mouseButton);

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
        handle_KEY_Q[game->scene](game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        handle_KEY_SPACE[game->scene](game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        handle_KEY_ESC[game->scene](game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR)
        handle_KEY_R[game->scene](game);
}
