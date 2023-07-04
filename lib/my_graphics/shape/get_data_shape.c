/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that get informations from the actual state of the shape
*/
#include "../include/shape.h"

// get the position of the shape
sfVector2f get_position_shape(shape_t * shape)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    switch (shape->type) {
        case CIRCLE:
            vect = sfCircleShape_getPosition((sfCircleShape *)(shape->shape));
        break;
        case RECT:
            vect = sfRectangleShape_getPosition(
                                        (sfRectangleShape *)(shape->shape));
        break;
        default: break;
    }
    return vect;
}

// get the rotation of the shape
float get_rotation_shape(shape_t * shape)
{
    float angle = 0.f;
    switch (shape->type) {
        case CIRCLE:
            angle = sfCircleShape_getRotation((sfCircleShape *)(shape->shape));
        break;
        case RECT:
            angle = sfRectangleShape_getRotation(
                                        (sfRectangleShape *)(shape->shape));
        break;
        default: break;
    }
    return angle;
}

// get the scale of the shape from its initial size
sfVector2f get_scale_shape(shape_t * shape)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    switch (shape->type) {
        case CIRCLE:
            vect = sfCircleShape_getScale((sfCircleShape *)(shape->shape));
        break;
        case RECT:
            vect = sfRectangleShape_getScale(
                                        (sfRectangleShape *)(shape->shape));
        break;
        default: break;
    }
    return vect;
}

// get origin of the shape
sfVector2f get_origin_shape(shape_t * shape)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    switch (shape->type) {
        case CIRCLE:
            vect = sfCircleShape_getOrigin((sfCircleShape *)(shape->shape));
        break;
        case RECT:
            vect = sfRectangleShape_getOrigin(
                                        (sfRectangleShape *)(shape->shape));
        break;
        default: break;
    }
    return vect;
}
