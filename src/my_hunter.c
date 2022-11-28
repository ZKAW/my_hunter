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
    linked_t *sprites = NULL;
    sfSprite *background = create_background("assets/background.png");
    sfTexture *pigeon = sfTexture_createFromFile("assets/pigeon.png", NULL);

    spawn_sprite(&sprites, (sfVector2f) {0, 0}, pigeon);
    spawn_sprite(&sprites, (sfVector2f) {110, 0}, pigeon);

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
