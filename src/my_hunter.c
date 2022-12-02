/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/

#include "../include/myhunter.h"
#include <stdio.h>
#include <stdlib.h>

int my_hunter(void)
{
    sfEvent event;
    game_t *game = create_game();

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_events(game, event);

        render_game(game);
        if (game->window == NULL || game->lives <= 0) {
            display_game_over(game);
            break;
        }
        sfRenderWindow_display(game->window);
    }

    destroy_game(game);
    return (0);
}
