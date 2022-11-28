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

void analyse_events(sfRenderWindow *window, sfEvent event, linked_t *sprites);
sfRenderWindow *create_window(void);
void close_window(sfRenderWindow *window);
int my_hunter(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfSprite *open_sprite(char *path);
sprite_t *create_sprite(sfTexture *texture, int nb_s,
                        float anim_speed, sfVector2f pos);
void display_sprite(sfRenderWindow *window, sprite_t *sprite, sfClock *clock);
void add_in_linked(linked_t **begin, sprite_t *data);
float get_time(sfClock *clock);
int get_texture_width(sfTexture *texture);
int get_texture_height(sfTexture *texture);
void display_sprites(linked_t *sprites, sfRenderWindow *window, sfClock *clock);
sfSprite *create_background(char *path);
sfTexture *create_pigeon(char *path);
void spawn_sprite(linked_t **sprites, sfVector2f pos, sfTexture *texture);
void remove_from_linked(linked_t **begin, sprite_t *data);

#endif /* !BSMYHUNTER_H_ */
