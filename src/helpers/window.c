/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** window
*/

#include "../../include/myhunter.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, 32};
    sfRenderWindow *window;
    char *w_title = "Kill The Suk";

    sfUint32 style = sfClose | sfTitlebar;
    window = sfRenderWindow_create(mode, w_title, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void destroy_game(game_t *game)
{
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

int get_window_width(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    return (size.x);
}

int get_window_height(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    return (size.y);
}
