/*
** EPITECH PROJECT, 2023
** button_free.c
** File description:
** -> Freeing button
*/

#include <my_macros.h>
#include "button.h"

void free_button(button_t *button)
{
    if (button) {
        FREE_IF_ALLOCATED(button->shape, sfRectangleShape_destroy);
        FREE_IF_ALLOCATED(button->text, sfText_destroy);
        if (button->fill_mode == BUTTON_FILL_WITH_SPRITE) {
            FREE_IF_ALLOCATED(button->fill.texture, sfTexture_destroy);
        }
    }
}
