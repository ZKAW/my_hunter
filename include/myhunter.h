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

    #define SUK_P "assets/sprites/suk_sprite.png"
    #define LIFE_BAR_P "assets/sprites/life_bar.png"
    #define BACKGROUND_P "assets/images/background.png"
    #define FONT_P "assets/fonts/font.ttf"
    #define MUSIC_P "assets/sounds/music.ogg"
    #define GAME_START_P "assets/sounds/game_start.ogg"
    #define GAME_OVER_P "assets/sounds/game_over.ogg"
    #define SUK_DEATH_P "assets/sounds/suk_death.ogg"
    #define CURSOR_P "assets/images/cursor.png"

typedef struct sprite_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f origin;
    int width;
    int height;
    int size;
    float anim_speed;
    float elapsed_time;
    float move_interval;
    float move_time;
    int does_rotate;
} sprite_t;

typedef struct linked_t {
    sprite_t *data;
    struct linked_t *next;
} linked_t;

typedef struct lifebar_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int width;
    int height;
    int size;
} lifebar_t;

typedef struct sounds_t {
    sfSound *suk_death;
    sfSound *game_start;
    sfSound *game_over;
    sfMusic *music;
} sounds_t;

typedef struct game_t {
    sfRenderWindow *window;
    sfSprite *background;
    sfSprite *cursor;
    lifebar_t *lifebar;
    sfTexture *suk;
    sfEvent event;
    sfClock *clock;
    linked_t *sprites;
    sounds_t *sounds;
    float spawn_time;
    int score;
    int lives;
    int scene;
    int display_cursor;
} game_t;

int my_hunter(void);
game_t *create_game(void);
void analyse_events(game_t *game, sfEvent event);
sfRenderWindow *create_window(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sprite_t *create_sprite(sfTexture *texture, int nb_frames,
                        float move_interval, sfVector2f pos);
sfSprite *create_background(void);
lifebar_t *create_lifebar(void);
void add_in_linked(linked_t **begin, sprite_t *data);
float get_time(sfClock *clock);
int get_texture_width(sfTexture *texture);
int get_texture_height(sfTexture *texture);
void display_sprites(game_t *game);
sfTexture *create_suk(char *path);
void remove_from_linked(linked_t **begin, sprite_t *data);
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
void destroy_outside_sprites(game_t *game);
void render_game(game_t *game);
void display_main_menu(game_t *game);
void display_game(game_t *game);
void display_pause_menu(game_t *game);
void display_game_over(game_t *game);
void destroy_sprites(game_t *game);
void destroy_outside_sprites(game_t *game);
void init_quit(game_t *game);
void restart_game(game_t *game);
sfMusic *load_music(char *path);
sfSound *load_sound(char *path);
void play_music(game_t *game);
void pause_music(game_t *game);
void stop_music(game_t *game);
sounds_t *create_sounds(void);
void pause_all_sounds(game_t *game);
void resume_all_sounds(game_t *game);
void stop_all_sounds(game_t *game);
sfSprite *create_cursor(void);
void display_cursor(game_t *game);

#endif /* !my_hunter_H_ */
