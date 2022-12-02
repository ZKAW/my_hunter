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
