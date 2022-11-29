/*
** EPITECH PROJECT, 2022
** bsmyhunter
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

    spawn_sprite(&game->sprites, game->pigeon, (sfVector2f) {0, 0}, 3);
    spawn_sprite(&game->sprites, game->pigeon, (sfVector2f) {0, 110}, 3);
    spawn_sprite(&game->sprites, game->pigeon, (sfVector2f) {0, 330}, 3);

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->background, NULL);
        display_score(game->window, game->score);
        display_sprites(game->sprites, game->window, game->clock);
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_events(game, event);
        sfRenderWindow_display(game->window);
    }

    sfRenderWindow_destroy(game->window);
    return (0);
}
