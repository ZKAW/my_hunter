/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/

#ifndef my_hunter_H_
    #define my_hunter_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "settings.h"

    #define SUK_P "assets/suk_sprite.png"
    #define BACKGROUND_P "assets/background.png"
    #define LIFE_BAR_P "assets/life_bar.png"
    #define FONT_P "assets/font.ttf"

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
    float elapsed_time;
    float move_interval;
    float move_time;
    int size;
} sprite_t;

typedef struct linked_t {
    sprite_t *data;
    struct linked_t *next;
} linked_t;

typedef struct lifebar_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    int width;
    int height;
    int size;
} lifebar_t;

typedef struct game_t {
    sfRenderWindow *window;
    sfSprite *background;
    sfSprite *life_bar;
    sfTexture *suk;
    sfEvent event;
    sfClock *clock;
    linked_t *sprites;
    float spawn_time;
    int score;
    int lives;
} game_t;

int my_hunter(void);
game_t *create_game(void);
void analyse_events(game_t *game, sfEvent event);
sfRenderWindow *create_window(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sprite_t *create_sprite(sfTexture *texture, int nb_frames,
                        float move_interval, sfVector2f pos);
sfSprite *create_background(char *path);
sfSprite *create_lifebar(char *path);
void display_sprite(sfRenderWindow *window, sprite_t *sprite, sfClock *clock);
void add_in_linked(linked_t **begin, sprite_t *data);
float get_time(sfClock *clock);
int get_texture_width(sfTexture *texture);
int get_texture_height(sfTexture *texture);
void display_sprites(game_t *game);
sfTexture *create_suk(char *path);
void spawn_sprite(linked_t **sprites, sfTexture *texture, sfVector2f pos,
                float move_interval);
void remove_from_linked(linked_t **begin, sprite_t *data);
void set_cursor(sfRenderWindow *window, char *path);
void display_text(sfRenderWindow *window, char *str, sfVector2f pos, int size);
int get_window_width(sfRenderWindow *window);
int get_window_height(sfRenderWindow *window);
void display_score(sfRenderWindow *window, int score);
void move_sprite(sprite_t *sprite, sfVector2f pos, sfClock *clock);
void spawn_sprites(game_t *game);
sfVector2f get_rand_spawn(void);
int get_rand_int(int min, int max);
float get_rand_float(float min, float max);
float deduce_anim_speed(float move_interval);
void display_lives(sfRenderWindow *window, int lives);
void destroy_game(game_t *game);
void update_lifebar(game_t *game, int lives);
void display_game_over(game_t *game);

#endif /* !my_hunter_H_ */
