/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** audio
*/

#include "../../include/myhunter.h"

sfMusic *load_music(void)
{
    sfMusic *music = sfMusic_createFromFile(MUSIC_P);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 50);
    return (music);
}

void play_music(game_t *game)
{
    if (sfMusic_getStatus(game->music) == sfPlaying) return;
    sfMusic_play(game->music);
}

void pause_music(game_t *game)
{
    if (sfMusic_getStatus(game->music) == sfPaused) return;
    sfMusic_pause(game->music);
}

void stop_music(game_t *game)
{
    if (sfMusic_getStatus(game->music) == sfStopped) return;
    sfMusic_stop(game->music);
}

