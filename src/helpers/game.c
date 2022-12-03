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
    game->background = create_background();
    game->lifebar = create_lifebar();
    game->cursor = create_cursor();
    game->suk = sfTexture_createFromFile(SUK_P, NULL);
    game->sounds = create_sounds();
    game->score_str = malloc(sizeof(char) * 11);
    game->score_str[0] = '0';
    game->score_str[1] = '\0';
    game->highscore = get_highscore();
    game->font = sfFont_createFromFile(FONT_P);
    game->lives = NB_LIVES;
    game->scene = 0;
    return (game);
}

void render_game(game_t *game)
{
    play_music(game);
    resume_all_sounds(game);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    spawn_sprites(game);
    display_score(game);
    update_lifebar(game, game->lives);
    display_sprites(game);
    destroy_outside_sprites(game);
}

void restart_game(game_t *game)
{
    game->lives = NB_LIVES;
    game->score = 0;
    game->score_str[0] = '0';
    game->score_str[1] = '\0';
    game->highscore = get_highscore();
    game->clock = sfClock_create();
    destroy_sprites(game);
    stop_music(game);
    stop_all_sounds(game);
    display_game(game);
}

float get_spawn_interval(game_t *game)
{
    float time_s = get_time(game->clock);

    float min_spawn_interval = MIN_SPAWN_INTERVAL - (time_s / 50);
    float max_spawn_interval = MAX_SPAWN_INTERVAL - (time_s / 25);
    if (min_spawn_interval < TOP_MIN_SPAWN_INTERVAL)
        min_spawn_interval = TOP_MIN_SPAWN_INTERVAL;
    if (max_spawn_interval < TOP_MAX_SPAWN_INTERVAL)
        max_spawn_interval = TOP_MAX_SPAWN_INTERVAL;

    return (get_rand_float(min_spawn_interval, max_spawn_interval));
}

float get_speed(game_t *game)
{
    float time_s = get_time(game->clock);

    float min_speed = MIN_SPEED + (time_s / (5 * my_intlen((int) time_s)));
    float max_speed = MAX_SPEED + (time_s / (5 * my_intlen((int) time_s)));
    if (min_speed > TOP_MIN_SPEED) min_speed = TOP_MIN_SPEED;
    if (max_speed > TOP_MAX_SPEED) max_speed = TOP_MAX_SPEED;

    return (get_rand_float(min_speed, max_speed));
}
