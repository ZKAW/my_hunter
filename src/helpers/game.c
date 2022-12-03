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
    game->suk = sfTexture_createFromFile(SUK_P, NULL);
    game->sounds = create_sounds();
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
    display_score(game->window, game->score);
    update_lifebar(game, game->lives);
    display_sprites(game);
    destroy_outside_sprites(game);
}

void restart_game(game_t *game)
{
    game->lives = NB_LIVES;
    game->score = 0;
    game->scene = 0;
    destroy_sprites(game);
    stop_music(game);
    stop_all_sounds(game);
    display_game(game);
}

void destroy_game(game_t *game)
{
    game->scene = 4;
    if (game == NULL)
        return;
    if (game->clock != NULL)
        sfClock_destroy(game->clock);
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->sprites == NULL || game->sprites->data == NULL)
        return;
    if (game->sprites->data->sprite != NULL)
        sfSprite_destroy(game->sprites->data->sprite);
    if (game->sprites->data->texture != NULL)
        sfTexture_destroy(game->sprites->data->texture);
}
