/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** window
*/

#include "../../include/bsmyhunter.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    char *w_title = "Kill The Suk";

    window = sfRenderWindow_create(mode, w_title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
