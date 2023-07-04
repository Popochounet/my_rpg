/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that display a text structure to layer
*/
#include "../include/text.h"

void draw_text(sfRenderTexture * texture, text_t * text)
{
    sfText * sftext = text->text;
    sfText_setFillColor(text->text, text->color_in);
    sfText_setOutlineThickness(text->text, text->thick);
    sfText_setOutlineColor(text->text, text->color_out);
    if (text->font == NULL) {
        text->font = sfFont_createFromFile("./fonts/Arial.ttf");
    }
    set_font_text(text, text->font);
    sfRenderTexture_drawText(texture, sftext, NULL);
}
