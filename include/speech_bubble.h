/*
** EPITECH PROJECT, 2023
** speech_bubble.h
** File description:
** -> Speech bubble display.
*/

#pragma once

#include <my_graphics.h>
#include <rpg_types.h>

typedef struct bubble_s {
    draw_t* text;
    draw_t* sprite;
    sfClock *clock;
    float time;
} bubble_t;

typedef struct list_bubble_s {
    bubble_t* bubble;
    struct list_bubble_s* next;
    struct list_bubble_s* previous;
} list_bubble_t;

void speech_bubble_free(bubble_t **bubble, bool free_layers);
bool speech_bubble_spawn(game_t* game, char* str, sfVector3f pos, float time);
void speech_bubble_clean(game_t *game);

void speech_bubble_resize_text_and_move
(data_t *text_data, draw_t *text_draw, char *str, sfTexture *bubble_texture);
bool speech_bubble_append
(list_bubble_t **head, bubble_t *bubble);
bool speech_bubble_remove(list_bubble_t **bubble);
void speech_bubble_remove_all(list_bubble_t **bubble);

extern const char *SPEECH_BUBBLE_SPRITE_PATH;
extern const unsigned SPEECH_BUBBLE_HEIGHT;
extern const unsigned SPEECH_BUBBLE_WIDTH;
extern const sfVector2f SPEECH_BUBBLE_SIZE;
extern const sfIntRect SPEECH_BUBBLE_AREA;
