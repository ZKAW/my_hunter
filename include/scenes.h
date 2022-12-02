/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** scenes
*/

#ifndef SCENES_H_
    #define SCENES_H_
    #include "myhunter.h"

static void (*handle_scene[])(game_t *) = {
    display_main_menu,
    display_game,
    display_pause_menu,
    display_game_over,
};

#endif /* !SCENES_H_ */
