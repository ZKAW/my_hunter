/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** game
*/

#include <stdlib.h>

#include "../../include/myhunter.h"
#include "../../include/my.h"

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    linked_t *sprites = NULL;

    game->window = create_window();
    game->clock = sfClock_create();
    game->sprites = sprites;
    game->background = create_background(BACKGROUND_P);
    game->life_bar = create_lifebar(LIFE_BAR_P);
    game->suk = sfTexture_createFromFile(SUK_P, NULL);
    game->lives = NB_LIVES;
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

float deduce_anim_speed(float move_interval)
{
    float anim_speed = 1.0f / move_interval;
    if (anim_speed < 0.2f) anim_speed = 0.2f;
    return (anim_speed);
}

void render_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    spawn_sprites(game);
    display_score(game->window, game->score);
    display_lives(game->window, game->lives);
    display_sprites(game);
    destroy_outside_sprites(game);
}