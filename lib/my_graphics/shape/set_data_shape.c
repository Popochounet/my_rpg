/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct linked to a shape
*/
#include "../include/shape.h"

// set the position of a shape
void set_pos_shape(shape_t * shape, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.y);
    if (shape->type == RECT) {
        sfRectangleShape_setPosition((sfRectangleShape *)(shape->shape), pos);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setPosition((sfCircleShape *)(shape->shape), pos);
    }
}

// set the size of a shape
void set_size_shape(shape_t * shape, sfVector2f size)
{
    if (shape->type == RECT) {
        sfRectangleShape_setSize((sfRectangleShape *)(shape->shape), size);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setRadius((sfCircleShape *)(shape->shape), size.x / 2.f);
    }
}

// set the rotation of a shape
void set_angle_shape(shape_t * shape, float angle)
{
    if (shape->type == RECT) {
        sfRectangleShape_setRotation((sfRectangleShape *)(shape->shape),
                                                                        angle);
    }
    if (shape->type == CIRCLE) {
        sfCircleShape_setRotation((sfCircleShape *)(shape->shape), angle);
    }
}

// set the position, the size and the rotation of a shape
void set_data_shape(shape_t * shape, data_t * data)
{
    set_pos_shape(shape, data->position);
    set_size_shape(shape, data->size);
    set_angle_shape(shape, data->angle);
}
