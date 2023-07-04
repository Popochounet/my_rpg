/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the color config of a text
*/
#include "../include/text.h"

// change the inner color of a text
void set_color_in_text(text_t * text, sfColor color)
{
    text->color_in = color;
    sfText_setFillColor(text->text, color);
}

// change the color of the outline of a text
void set_color_out_text(text_t * text, sfColor color)
{
    text->color_out = color;
    sfText_setOutlineColor(text->text, color);
}

// change the thickness of the outline of a text
void set_thick_text(text_t * text, int thick)
{
    text->thick = thick;
    sfText_setOutlineThickness(text->text, thick);
}

// change inner color, outline color and outline thickness of a text
void set_attributes_text(text_t * text, sfColor color_in,
                    sfColor color_out, int thick)
{
    set_color_in_text(text, color_in);
    set_color_out_text(text, color_out);
    set_thick_text(text, thick);
}
