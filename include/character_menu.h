/*
** EPITECH PROJECT, 2023
** character_menu.h
** File description:
** -> A menu to select a character.
*/

#pragma once

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <button.h>
#include <characters.h>

#ifdef N_CHARACTERS
    #undef N_CHARACTERS
#endif
#define N_CHARACTERS (7)

#ifdef SPRITE_FILENAMES
    #undef SPRITE_FILENAMES
#endif
#define SPRITE_FILENAMES(sprite) {  \
    "images/sprites/" sprite "/" sprite ".png",        \
    "images/sprites/" sprite "/" sprite "_de_dos.png"  \
}

#ifdef UTF8
    #undef UTF8
#endif
#define UTF8(str) (sfUint32*)L##str

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfClock *clock;
    sfText *descriptions[N_CHARACTERS];
    button_t buttons[N_CHARACTERS];
    sfEvent event;
    unsigned character_selected;
    unsigned allocated_buttons;
} character_menu_t;

#ifdef BOTTOM_RIGHT_BUTTON
    #undef BOTTOM_RIGHT_BUTTON
#endif
#define BOTTOM_RIGHT_BUTTON(menu_ptr) ((menu_ptr)->buttons[N_CHARACTERS - 1])

extern const char *SPRITES_FILENAMES[N_CHARACTERS][2];
extern const sfUint32 *CHARACTER_NAMES_UTF8[N_CHARACTERS];
extern const char *CHARACTER_NAMES_ANSI[N_CHARACTERS];
extern const float DESCRIPTION_Y_OFFSET;
extern const sfUint32 *CHARACTER_DESCRIPTION[N_CHARACTERS];
extern const sfVector2f DESCRIPTION_POSITION;

bool character_menu_init(character_menu_t *menu);
void character_menu_free(character_menu_t *menu);

bool character_menu_shrink_window
(sfRenderWindow *window, button_t *bottom_right_button);
character_type_t select_character(void);
