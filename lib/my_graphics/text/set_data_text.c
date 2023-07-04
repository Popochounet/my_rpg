/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct linked to a text
*/
#include "../include/text.h"

// set the position of a text
void set_pos_text(text_t * text, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.y);
    sfText_setPosition(text->text, pos);
}

// set the size of a text
void set_size_text(text_t * text, sfVector2f size)
{
    sfText_setCharacterSize(text->text, size.y);
}

// set the rotation of a text
void set_angle_text(text_t * text, float angle)
{
    sfText_setRotation(text->text, angle);
}

// set the position, the size and the rotation of a text
void set_data_text(text_t * text, data_t * data)
{
    set_pos_text(text, data->position);
    set_size_text(text, data->size);
    set_angle_text(text, data->angle);
}
