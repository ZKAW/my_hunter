/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** bsmyhunter
*/

#ifndef BSMYHUNTER_H_
    #define BSMYHUNTER_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct sprite_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    int width;
    int height;
    float anim_speed;
    float elasped_time;
    int size;
} sprite_t;

typedef struct linked_t {
    sprite_t *data;
    struct linked_t *next;
} linked_t;

void analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
sfRenderWindow *create_window(void);
void close_window(sfRenderWindow *window);
int my_hunter(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfSprite *open_sprite(char *path);
sfIntRect create_rect(int top, int left, int width, int height);
void add_in_linked(linked_t **begin, sprite_t *data);

#endif /* !BSMYHUNTER_H_ */
