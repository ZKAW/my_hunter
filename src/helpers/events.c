/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** base_events
*/

#include <stdio.h>
#include "../../include/myhunter.h"

void manage_mouse_click(sfMouseButtonEvent event, linked_t *sprites)
{
    int x = event.x;
    int y = event.y;

    linked_t *tmp = sprites;
    while (tmp != NULL) {
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->data->sprite);
        if (sfFloatRect_contains(&rect, x, y)) {
            printf("You clicked on the sprite!\n");
            remove_from_linked(&sprites, tmp->data);
            break;
        }
        tmp = tmp->next;
    }

    printf("Mouse x=%d y=%d\n", x, y);
}

void analyse_events(sfRenderWindow *window, sfEvent event, linked_t *sprites)
{
    if (event.type == sfEvtClosed)
        close_window(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, sprites);
}
