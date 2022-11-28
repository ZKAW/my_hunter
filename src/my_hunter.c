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
    sprite_t *pigeon = create_sprite("assets/pigeon.png",
                                    3, 0.2, (sfVector2f){110, 110});
    sprite_t *pigeon2 = create_sprite("assets/pigeon.png",
                                    3, 0.2, (sfVector2f){110, 250});

    add_in_linked(&sprites, pigeon);
    add_in_linked(&sprites, pigeon2);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_sprites(sprites, window, clock);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, pigeon->sprite);
        sfRenderWindow_display(window);
    }
    close_window(window);
    return (0);
}
