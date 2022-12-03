/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** audio
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

sounds_t *create_sounds(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    sounds->game_start = load_sound(GAME_START_P);
    sounds->game_over = load_sound(GAME_OVER_P);
    sounds->suk_death = load_sound(SUK_DEATH_P);
    sounds->music = load_music(MUSIC_P);
    return (sounds);
}
