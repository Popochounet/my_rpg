/*
** EPITECH PROJECT, 2023
** countryball.h
** File description:
** -> Declarations for countryball animation.
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <audio.h>

typedef struct countryball_s {
    sfRenderWindow *window;
    sfTexture *spritesheet;
    sfSprite *sprite;
    sfClock *clock;
    sfText *lose_text;
    sfFont *font;
} countryball_t;

void countryball_free(countryball_t *countryball);
bool countryball_49_3(audio_t *audio);

extern const char *const SPRITESHEET_PATH;
extern const unsigned N_COLUMNS;
extern const unsigned N_LINES;
extern const unsigned N_FRAMES;
extern const unsigned FRAME_DELAY_MICROSECONDS;
extern const sfVector2f FRAME_SIZE;
extern const char *const LOSE_TEXT;
extern const sfVector2f LOSE_TEXT_POS;
