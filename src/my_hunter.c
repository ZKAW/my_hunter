/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** my_hunter
*/

#include "../include/bsmyhunter.h"
#include <stdio.h>
#include <stdlib.h>

int my_hunter(void)
{
    sfEvent event;
    sfRenderWindow *window = create_window();
    sfClock *clock = sfClock_create();
    sfSprite *background = create_background("assets/background.png");
    linked_t *sprites = NULL;

    spawn_pigeon(&sprites, (sfVector2f) {0, 0});
    spawn_pigeon(&sprites, (sfVector2f) {110, 0});
    spawn_pigeon(&sprites, (sfVector2f) {220, 0});

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        display_sprites(sprites, window, clock);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, sprites);
        sfRenderWindow_display(window);
    }
    close_window(window);
    return (0);
}
