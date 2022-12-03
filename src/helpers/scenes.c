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
    if (game->scene != 0) game->highscore = get_highscore();
    game->scene = 0;
    stop_all_sounds(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game, "KILL THE SUK",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100}, 85);
    display_text(game, "Press SPACE to start", (sfVector2f)
                {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100}, 50);
    display_text(game, "Press Q to exit game", (sfVector2f)
                {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 185}, 50);

    display_text(game, "Highscore: ", (sfVector2f) {50, 75}, 30);
    display_text(game, my_itoa(game->highscore), (sfVector2f) {400, 75}, 30);
    sfRenderWindow_display(game->window);
}

void display_game(game_t *game)
{
    if (game->scene != 1)
        sfSound_play(game->sounds->game_start);

    game->scene = 1;
    render_game(game);
}

void display_pause_menu(game_t *game)
{
    if (game->scene == 1) {
        sfSound_stop(game->sounds->game_start);
    }
    game->scene = 2;
    pause_music(game);
    pause_all_sounds(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game, "PAUSE",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100}, 100);
    display_text(game, "Press ESC to resume",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100}, 50);
    display_text(game, "Press R to restart",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 185}, 50);
    display_text(game, "Press Q to quit to main menu",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 270}, 50);
    sfRenderWindow_display(game->window);
}

void display_game_over(game_t *game)
{
    game->scene = 3;
    char *score_text = "Score: ";
    if (game->score > game->highscore) {
        score_text = "New highscore!! Score: ";
    }
    stop_music(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_text(game, "GAME OVER",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 200}, 100);
    display_text(game, score_text,
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, 50);
    display_text(game, my_itoa(game->score),
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100}, 50);
    display_text(game, "Press Q to quit to main menu", (sfVector2f)
                {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 250}, 50);
    display_text(game, "Press R to restart",
                (sfVector2f) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 350}, 50);
    sfRenderWindow_display(game->window);
}

void init_quit(game_t *game)
{
    game->scene = 4;
}
