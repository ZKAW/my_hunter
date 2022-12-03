/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/

#include "../include/myhunter.h"
#include "../include/scenes.h"

#include <stdio.h>
#include <stdlib.h>

int my_hunter(void)
{
    sfEvent event;
    game_t *game = create_game();

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_events(game, event);

        handle_scene[game->scene](game);
        if (game->scene == 4) break;
        if ((game->window == NULL || game->lives <= 0) && (game->scene == 1)) {
            stop_all_sounds(game);
            sfSound_play(game->sounds->game_over);
            game->scene = 3;
        }

        sfRenderWindow_display(game->window);
    }
    destroy_game(game);

    return (0);
}
