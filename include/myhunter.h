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

    #define PIGEON_P "assets/pigeon.png"
    #define BACKGROUND_P "assets/background2.png"
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
    float elasped_time;
    float move_speed;
    float move_time;
    int size;
} sprite_t;

typedef struct linked_t {
    sprite_t *data;
    struct linked_t *next;
} linked_t;

typedef struct game_t {
    sfRenderWindow *window;
    sfSprite *background;
    sfTexture *pigeon;
    sfEvent event;
    sfClock *clock;
    linked_t *sprites;
    int score;
    int lives;
} game_t;

int my_hunter(void);
void analyse_events(game_t *game, sfEvent event);
sfRenderWindow *create_window(void);
void move_rect(sfIntRect *rect, int offset, int max_value);
sprite_t *create_sprite(sfTexture *texture, int nb_frames,
                        float move_speed, sfVector2f pos);
sfSprite *create_background(char *path);
void display_sprite(sfRenderWindow *window, sprite_t *sprite, sfClock *clock);
void add_in_linked(linked_t **begin, sprite_t *data);
float get_time(sfClock *clock);
int get_texture_width(sfTexture *texture);
int get_texture_height(sfTexture *texture);
void display_sprites(linked_t *sprites, sfRenderWindow *window, sfClock *clock);
sfTexture *create_pigeon(char *path);
void spawn_sprite(linked_t **sprites, sfTexture *texture, sfVector2f pos,
                float move_speed);
void remove_from_linked(linked_t **begin, sprite_t *data);
void set_cursor(sfRenderWindow *window, char *path);
void display_text(sfRenderWindow *window, char *str, sfVector2f pos, int size);
int get_window_width(sfRenderWindow *window);
int get_window_height(sfRenderWindow *window);
void display_score(sfRenderWindow *window, int score);
void move_sprite(sprite_t *sprite, sfVector2f pos, sfClock *clock);
game_t *create_game(void);

#endif /* !BSMYHUNTER_H_ */