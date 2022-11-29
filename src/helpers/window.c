/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** window
*/

#include "../../include/myhunter.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
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
