/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** base_events
*/

#include <stdio.h>
#include "../../include/myhunter.h"

void manage_mouse_click(game_t *game, sfMouseButtonEvent event)
{
    int x = event.x;
    int y = event.y;

    linked_t *tmp = game->sprites;
    while (tmp != NULL) {
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->data->sprite);
        if (sfFloatRect_contains(&rect, x, y)) {
            printf("You clicked on the sprite!\n");
            game->score++;
            remove_from_linked(&game->sprites, tmp->data);
            break;
        }
        tmp = tmp->next;
    }
}

void analyse_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(game, event.mouseButton);
}
