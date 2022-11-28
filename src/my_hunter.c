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
    sprite_t *pigeon = create_sprite("assets/pigeon.png",
                                    3, 0.2, (sfVector2f){110, 110});

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_sprite(window, pigeon, clock);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, pigeon->sprite);
        sfRenderWindow_display(window);
    }
    close_window(window);
    return (0);
}
