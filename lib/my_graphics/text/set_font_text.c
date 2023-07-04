/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply a font to a text
*/
#include "../include/text.h"

void set_font_text(text_t * text, sfFont * font)
{
    text->font = font;
    if (font != NULL) {
        sfText_setFont(text->text, font);
    }
}
