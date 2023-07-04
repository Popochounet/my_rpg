/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that get information from actual state of the text
*/
#include "../include/text.h"

// get the position of the text
sfVector2f get_position_text(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getPosition((sfText *)(text->text));
    return vect;
}

// get the rotation of the text
float get_rotation_text(text_t * text)
{
    float angle = 0.f;
    angle = sfText_getRotation((sfText *)(text->text));
    return angle;
}

// get the scale of the text from its initial size
sfVector2f get_scale_text(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getScale((sfText *)(text->text));
    return vect;
}

// get the origin of the text
sfVector2f get_origin_text(text_t * text)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfText_getOrigin((sfText *)(text->text));
    return vect;
}

const char * get_string_text(text_t * text)
{
    return text->string;
}
