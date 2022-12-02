/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** key_events
*/

#ifndef KEY_EVENTS_H_
    #define KEY_EVENTS_H_
    #include "myhunter.h"

static void (*handle_KEY_Q[])(game_t *) = {
    init_quit,
    display_game,
    display_main_menu,
    display_main_menu,
};

static void (*handle_KEY_SPACE[])(game_t *) = {
    restart_game,
    display_game,
    display_pause_menu,
    display_game_over,
};

static void (*handle_KEY_ESC[])(game_t *) = {
    display_main_menu,
    display_pause_menu,
    display_game,
    display_game_over,
};

static void (*handle_KEY_R[])(game_t *) = {
    display_main_menu,
    display_game,
    restart_game,
    restart_game,
};

#endif /* !KEY_EVENTS_H_ */
