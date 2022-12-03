/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** audio
*/

#include "../../include/myhunter.h"

sfMusic *load_music(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, MUSIC_VOLUME);
    return (music);
}

void play_music(game_t *game)
{
    if (sfMusic_getStatus(game->sounds->music) == sfPlaying) return;
    if (sfSound_getStatus(game->sounds->game_start) == sfPlaying) return;
    sfMusic_play(game->sounds->music);
}

void pause_music(game_t *game)
{
    if (sfMusic_getStatus(game->sounds->music) == sfPaused) return;
    sfMusic_pause(game->sounds->music);
}

void stop_music(game_t *game)
{
    if (sfMusic_getStatus(game->sounds->music) == sfStopped) return;
    sfMusic_stop(game->sounds->music);
}
