/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a shape struct
*/
#include "../include/shape.h"

shape_t * init_shape(void)
{
    shape_t * shape = malloc(sizeof(shape_t));
    shape->type = NO_SHAPE;
    shape->shape = NULL;
    shape->color_in = (sfColor){0.0, 0.0, 0.0, 0.0};
    shape->color_out = (sfColor){0.0, 0.0, 0.0, 0.0};
    shape->thick = 0;
    return shape;
}
