/*
** EPITECH PROJECT, 2023
** button_title.c
** File description:
** -> Button title management.
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>
#include "button.h"

void button_set_utf8_title
(button_t *button, sfUint32 *utf8, bool free_old_title)
{
    if (free_old_title) {
        if (button->use_utf8_title) {
            FREE_IF_ALLOCATED(button->title.utf8, free);
        } else {
            FREE_IF_ALLOCATED(button->title.ansi, free);
        }
    }
    button->use_utf8_title = true;
    button->title.utf8 = utf8;
}

void button_set_ansi_title
(button_t *button, char *ansi, bool free_old_title)
{
    if (free_old_title) {
        if (button->use_utf8_title) {
            FREE_IF_ALLOCATED(button->title.utf8, free);
        } else {
            FREE_IF_ALLOCATED(button->title.ansi, free);
        }
    }
    button->use_utf8_title = false;
    button->title.ansi = ansi;
}

size_t button_title_length(button_t *button)
{
    if (button->use_utf8_title) {
        return my_wstrlen((wchar_t *)button->title.utf8);
    }
    return my_strlen(button->title.ansi);
}

void update_button_title(button_t *button)
{
    sfText_setCharacterSize(button->text, button->text_size);
    if (button->use_utf8_title) {
        sfText_setUnicodeString(button->text, button->title.utf8);
    } else {
        sfText_setString(button->text, button->title.ansi);
    }
    sfText_setFont(button->text, button->font);
}
