/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** base_events
*/

#include <stdio.h>
#include "../../include/bsmyhunter.h"

void manage_mouse_click(sfMouseButtonEvent event, sfSprite *sprite)
{
    int x = event.x;
    int y = event.y;

    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&rect, x, y))
        printf("You clicked on the sprite!\n");

    printf("Mouse x=%d y=%d\n", x, y);
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite)
{
    if (event.type == sfEvtClosed)
        close_window(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, sprite);

}
