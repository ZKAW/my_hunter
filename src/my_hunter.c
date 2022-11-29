/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** my_hunter
*/

#include "../include/myhunter.h"
#include <stdio.h>
#include <stdlib.h>

int my_hunter(void)
{
    sfEvent event;
    sfRenderWindow *window = create_window();
    sfClock *clock = sfClock_create();
    linked_t *sprites = NULL;
    sfSprite *background = create_background(BACKGROUND_S);
    sfTexture *pigeon = sfTexture_createFromFile(PIGEON_S, NULL);

    spawn_sprite(&sprites, (sfVector2f) {0, 0}, pigeon, 3);
    spawn_sprite(&sprites, (sfVector2f) {0, 110}, pigeon, 5);
    spawn_sprite(&sprites, (sfVector2f) {0, 330}, pigeon, 7);

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
