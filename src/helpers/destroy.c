/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** destroy
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

void destroy_sounds(game_t *game)
{
    stop_all_sounds(game);
    stop_music(game);
    if (game->sounds->game_start != NULL)
        sfSound_destroy(game->sounds->game_start);
    if (game->sounds->game_over != NULL)
        sfSound_destroy(game->sounds->game_over);
    if (game->sounds->suk_death != NULL)
        sfSound_destroy(game->sounds->suk_death);
    if (game->sounds->music != NULL)
        sfMusic_destroy(game->sounds->music);
    free(game->sounds);
}

void destroy_lifebar(game_t *game)
{
    sfTexture_destroy(game->lifebar->texture);
    sfSprite_destroy(game->lifebar->sprite);
    free(game->lifebar);
}

void destroy_sprites(game_t *game)
{
    linked_t *tmp_sprites = game->sprites;
    while (tmp_sprites != NULL) {
        remove_from_linked(&game->sprites, tmp_sprites->data);
        tmp_sprites = game->sprites;
    }
    game->sprites = NULL;
}

void destroy_outside_sprites(game_t *game)
{
    linked_t *tmp_sprites = game->sprites;
    while (tmp_sprites != NULL) {
        if (tmp_sprites->data->pos.x > get_window_width(game->window)) {
            remove_from_linked(&game->sprites, tmp_sprites->data);
            game->lives--;
            tmp_sprites = game->sprites;
            continue;
        }
        tmp_sprites = tmp_sprites->next;
    }
}

void destroy_game(game_t *game)
{
    game->scene = 4;
    if (game == NULL) return;
    if (game->clock != NULL) sfClock_destroy(game->clock);
    if (game->window != NULL) sfRenderWindow_destroy(game->window);
    if (game->sounds != NULL) destroy_sounds(game);
    if (game->sprites != NULL) destroy_sprites(game);
    if (game->suk != NULL) sfTexture_destroy(game->suk);
    if (game->lifebar != NULL) destroy_lifebar(game);
    if (game->background != NULL) sfSprite_destroy(game->background);
    if (game != NULL) free(game);
}
