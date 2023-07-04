/*
** EPITECH PROJECT, 2023
** button.h
** File description:
** -> Button protorype in pure CSFML
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

static const unsigned DEFAULT_CHAR_SIZE = 32;

typedef union {
    sfColor color;
    sfTexture *texture;
} button_fill_t;

typedef enum {
    BUTTON_TITLE_ABOVE,
    BUTTON_TITLE_BENEATH,
    BUTTON_TITLE_MIDDLE,
    BUTTON_TITLE_HIDDEN
} button_title_pos_t;

typedef enum {
    BUTTON_FILL_UNINITIALIZED,
    BUTTON_FILL_WITH_SPRITE,
    BUTTON_FILL_WITH_COLOR
} button_fill_mode_t;

typedef union {
    char *ansi;
    sfUint32 *utf8;
} button_title_t;

typedef enum {
    BUTTON_INVALID = 1 << 4,
    BUTTON_PRESSED = 1 << 3,
    BUTTON_HOVERED = 1 << 2,
    BUTTON_RELEASED = 1 << 1
} button_state_t;

typedef struct {
    button_state_t state;
    button_title_t title;
    bool use_utf8_title;
    button_fill_t fill;
    button_title_pos_t title_pos;
    button_fill_mode_t fill_mode;
    bool keep_texture_size;
    sfFloatRect area;
    sfRectangleShape *shape;
    sfText *text;
    sfColor text_color;
    sfFont *font;
    unsigned text_size;
} button_t;

// button_init.c
bool init_button_base(button_t *button);
void button_fill_color(button_t *button, sfColor color);
bool button_fill_sprite(button_t *button, const char *file);
bool switch_button_mode(button_t *button, sfColor color, char *filename);

// button_misc.c
void convert_float_rect_to_rectangle_shape
(sfFloatRect *rect, sfRectangleShape *shape);
void convert_rectangle_shape_to_float_rect
(sfRectangleShape *shape, sfFloatRect *rect);
bool is_mouse_in_rect(sfRenderWindow *window, sfFloatRect *rect);
void resize_and_center_text(sfFloatRect *rect, sfText *text);
void update_button_state
(button_t *button, sfRenderWindow *window, sfEvent event);

// button_title.c
void button_set_utf8_title
(button_t *button, sfUint32 *utf8, bool free_old_title);
void button_set_ansi_title
(button_t *button, char *ansi, bool free_old_title);
size_t button_title_length(button_t *button);
void update_button_title(button_t *button);

// button_draw.c
void draw_button(sfRenderWindow *window, button_t *button);

// button_free.c
void free_button(button_t *button);
