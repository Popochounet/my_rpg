/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the text
*/
#include "../include/text.h"

// move the text of the given offset
void move_text(text_t * text, sfVector2f offset)
{
    sfText_move((sfText *)(text->text), offset);
}

// scale the size of the text
void scale_text(text_t * text, sfVector2f scale)
{
    sfText_scale((sfText *)(text->text), scale);
}

// rotate the text of the given angle
void rotate_text(text_t * text, float angle)
{
    sfText_rotate((sfText *)(text->text), angle);
}

// move, scale and rotate the text with the parameters
void modify_text(text_t * text, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    move_text(text, offset);
    scale_text(text, scale);
    rotate_text(text, angle);
}
