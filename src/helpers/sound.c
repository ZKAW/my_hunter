/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** sound
*/

#include "../../include/myhunter.h"
#include <stdlib.h>

sfSound *load_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, buffer);
    sfSound_setVolume(sound, SOUND_VOLUME);
    return (sound);
}

void play_sound(sfSound *sound)
{
    sfSound_play(sound);
}

void pause_all_sounds(game_t *game)
{
    if (sfSound_getStatus(game->sounds->suk_death) == sfPlaying)
        sfSound_pause(game->sounds->suk_death);
    if (sfSound_getStatus(game->sounds->game_start) == sfPlaying)
        sfSound_pause(game->sounds->game_start);
    if (sfSound_getStatus(game->sounds->game_over) == sfPlaying)
        sfSound_pause(game->sounds->game_over);
    if (sfMusic_getStatus(game->sounds->music) == sfPlaying)
        sfMusic_pause(game->sounds->music);
}

void resume_all_sounds(game_t *game)
{
    if (sfSound_getStatus(game->sounds->suk_death) == sfPaused)
        sfSound_play(game->sounds->suk_death);
    if (sfSound_getStatus(game->sounds->game_start) == sfPaused)
        sfSound_play(game->sounds->game_start);
    if (sfSound_getStatus(game->sounds->game_over) == sfPaused)
        sfSound_play(game->sounds->game_over);
    if (sfMusic_getStatus(game->sounds->music) == sfPaused)
        sfMusic_play(game->sounds->music);
}

void stop_all_sounds(game_t *game)
{
    if (sfSound_getStatus(game->sounds->suk_death) == sfPlaying)
        sfSound_stop(game->sounds->suk_death);
    if (sfSound_getStatus(game->sounds->game_start) == sfPlaying)
        sfSound_stop(game->sounds->game_start);
    if (sfSound_getStatus(game->sounds->game_over) == sfPlaying)
        sfSound_stop(game->sounds->game_over);
    if (sfMusic_getStatus(game->sounds->music) == sfPlaying)
        sfMusic_stop(game->sounds->music);
}
