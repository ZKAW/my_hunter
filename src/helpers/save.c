/*
** EPITECH PROJECT, 2022
** myhunter
** File description:
** save
*/

#include "../../include/myhunter.h"
#include "../../include/my.h"

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int get_highscore(void)
{
    int fd = open(".highscore", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 10);
    int highscore = 0;

    if (fd == -1)
        return (0);
    read(fd, buffer, 10);
    highscore = my_getnbr(buffer);
    close(fd);
    return (highscore);
}

void set_highscore(int score)
{
    if (score <= get_highscore()) return;

    int fd = open(".highscore", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) return;

    write(fd, my_itoa(score), my_intlen(score));
    close(fd);
}
