/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the shape
*/
#include "../include/shape.h"

// move the shape of the given offset
void move_shape(shape_t * shape, sfVector2f offset)
{
    switch (shape->type) {
        case CIRCLE:
            sfCircleShape_move((sfCircleShape *)(shape->shape), offset);
        break;
        case RECT:
            sfRectangleShape_move((sfRectangleShape *)(shape->shape), offset);
        break;
        default: break;
    }
}

// scale the size of the shape
void scale_shape(shape_t * shape, sfVector2f scale)
{
    switch (shape->type) {
        case CIRCLE:
            sfCircleShape_scale((sfCircleShape *)(shape->shape), scale);
        break;
        case RECT:
            sfRectangleShape_scale((sfRectangleShape *)(shape->shape), scale);
        break;
        default: break;
    }
}

// rotate the shape of the given angle
void rotate_shape(shape_t * shape, float angle)
{
    switch (shape->type) {
        case CIRCLE:
            sfCircleShape_rotate((sfCircleShape *)(shape->shape), angle);
        break;
        case RECT:
            sfRectangleShape_rotate((sfRectangleShape *)(shape->shape), angle);
        break;
        default: break;
    }
}

// move, scale and rotate the shape
void modify_shape(shape_t * shape, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    move_shape(shape, offset);
    scale_shape(shape, scale);
    rotate_shape(shape, angle);
}
