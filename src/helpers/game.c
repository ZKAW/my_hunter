/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** game
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    linked_t *sprites = NULL;

    game->window = create_window();
    game->clock = sfClock_create();
    game->sprites = sprites;
    game->background = create_background(BACKGROUND_P);
    game->pigeon = sfTexture_createFromFile(PIGEON_P, NULL);
    game->lives = 3;
    return (game);
}

sfVector2f get_rand_spawn(void)
{
    int x;
    int y;

    y = rand() % 650 + 110;
    x = rand() % 200;

    return ((sfVector2f) {x, y});
}

float get_rand_float(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * (max - min));
}
