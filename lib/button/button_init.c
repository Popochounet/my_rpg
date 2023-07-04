/*
** EPITECH PROJECT, 2023
** button_init.c
** File description:
** -> Button initialization
*/

#include <my_macros.h>
#include "button.h"

static void init_button_struct(button_t *button)
{
    (*button) = (button_t) {
        .state = BUTTON_RELEASED,
        .title = { .ansi = NULL },
        .title_pos = BUTTON_TITLE_MIDDLE,
        .fill_mode = BUTTON_FILL_UNINITIALIZED,
        .area = { .left = 0, .top = 0, .width = 250, .height = 100 },
        .text_color = sfBlack,
        .text = sfText_create(),
        .shape = sfRectangleShape_create(),
        .keep_texture_size = true,
        .font = NULL,
        .text_size = DEFAULT_CHAR_SIZE,
        .use_utf8_title = false
    };
}

bool init_button_base(button_t *button)
{
    init_button_struct(button);
    if (!button->text || !button->shape) {
        FREE_IF_ALLOCATED(button->text, sfText_destroy);
        FREE_IF_ALLOCATED(button->shape, sfRectangleShape_destroy);
        return false;
    }
    sfText_setFillColor(button->text, button->text_color);
    return true;
}

void button_fill_color(button_t *button, sfColor color)
{
    if (button->fill_mode == BUTTON_FILL_WITH_SPRITE) {
        FREE_IF_ALLOCATED(button->fill.texture, sfTexture_destroy);
    }
    button->fill.color = color;
    button->fill_mode = BUTTON_FILL_WITH_COLOR;
}

bool button_fill_sprite(button_t *button, const char *file)
{
    sfVector2u texture_size = { 0, 0 };

    if (button->fill_mode == BUTTON_FILL_WITH_SPRITE) {
        FREE_IF_ALLOCATED(button->fill.texture, sfTexture_destroy);
    }
    button->fill_mode = BUTTON_FILL_WITH_SPRITE;
    button->fill.texture = sfTexture_createFromFile(file, NULL);
    if (!button->fill.texture) {
        FREE_IF_ALLOCATED(button->fill.texture, sfTexture_destroy);
        button->fill_mode = BUTTON_FILL_UNINITIALIZED;
        return false;
    }
    if (button->keep_texture_size) {
        texture_size = sfTexture_getSize(button->fill.texture);
        button->area.width = texture_size.x;
        button->area.height = texture_size.y;
    }
    sfRectangleShape_setFillColor(button->shape, sfWhite);
    sfRectangleShape_setTexture(button->shape, button->fill.texture, true);
    return true;
}

bool switch_button_mode(button_t *button, sfColor color, char *filename)
{
    switch (button->fill_mode) {
    case BUTTON_FILL_UNINITIALIZED:
        return false;

    case BUTTON_FILL_WITH_COLOR:
        return button_fill_sprite(button, filename);

    default:
        button_fill_color(button, color);
        return true;
    }
}
