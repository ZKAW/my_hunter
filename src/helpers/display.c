/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** display
*/

#include "../../include/myhunter.h"
#include "../../include/my.h"
#include <stdlib.h>

void display_text(sfRenderWindow *window, char *str, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT_P);
    sfVector2f position = pos;

    int len = my_strlen(str);
    if (len > 1) {
        pos.x -= (len * size) / 2;
    } else {
        pos.x -= size;
    }
    pos.y -= size;

    if (pos.x < 0) pos.x = position.x;
    if (pos.y < 0) pos.y = position.y;

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
}

void display_score(sfRenderWindow *window, int score)
{
    char *str = my_itoa(score);
    int size = 30;

    display_text(window, "Score: ", (sfVector2f) {50, 75}, size);
    display_text(window, str, (sfVector2f) {275, 75}, size);
}

void display_lives(sfRenderWindow *window, int lives)
{
    char *str = my_itoa(lives);
    int size = 30;

    display_text(window, "Lives: ", (sfVector2f) {SCREEN_WIDTH - 300, 50},
                size);
    display_text(window, str, (sfVector2f) {SCREEN_WIDTH - 90, 50}, size);
}
