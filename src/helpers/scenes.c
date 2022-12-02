/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** scenes:
** 0: main menu
** 1: game
** 2: pause menu
** 3: game over
** 4: quit
*/

#include "../../include/myhunter.h"
#include "../../include/my.h"

void display_main_menu(game_t *game)
{
    game->scene = 0;
    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game->window, "KILL THE SUK", (sfVector2f) {SCREEN_WIDTH / 2 -
                100, SCREEN_HEIGHT / 2 - 100}, 85);
    display_text(game->window, "Press SPACE to start", (sfVector2f)
                {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 85}, 50);
    display_text(game->window, "Press ESC to exit", (sfVector2f) {SCREEN_WIDTH
                / 2 - 100, SCREEN_HEIGHT / 2 + 185}, 50);
    sfRenderWindow_display(game->window);
}

void display_game(game_t *game)
{
    game->scene = 1;
    render_game(game);
}

void display_pause_menu(game_t *game)
{
    game->scene = 2;
    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game->window, "PAUSE", (sfVector2f) {SCREEN_WIDTH / 2 -
                100, SCREEN_HEIGHT / 2 - 100}, 100);
    display_text(game->window, "Press SPACE to resume",
                (sfVector2f) {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2}, 50);
    display_text(game->window, "Press ESC to exit", (sfVector2f) {SCREEN_WIDTH
                / 2 - 100, SCREEN_HEIGHT / 2 + 100}, 50);
    sfRenderWindow_display(game->window);
}

void display_game_over(game_t *game)
{
    game->scene = 3;
    int score_tab = 50;
    int score_len = my_intlen(game->score);
    if (score_len > 1) score_tab = 50 * score_len;

    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game->window, "GAME OVER", (sfVector2f) {SCREEN_WIDTH / 2 -
                450, SCREEN_HEIGHT / 2 - 200}, 100);
    display_text(game->window, "Score: ", (sfVector2f) {SCREEN_WIDTH / 2 -
                175, SCREEN_HEIGHT / 2}, 50);
    display_text(game->window, my_itoa(game->score), (sfVector2f) {SCREEN_WIDTH
                / 2 - score_tab, SCREEN_HEIGHT / 2 + 100}, 50);
    display_text(game->window, "Press ESC to exit", (sfVector2f) {SCREEN_WIDTH
                / 2 - 425, SCREEN_HEIGHT / 2 + 250}, 50);
    display_text(game->window, "Press R to restart", (sfVector2f) {SCREEN_WIDTH
                / 2 - 450, SCREEN_HEIGHT / 2 + 350}, 50);
    sfRenderWindow_display(game->window);
}

void init_quit(game_t *game)
{
    game->scene = 4;
}
