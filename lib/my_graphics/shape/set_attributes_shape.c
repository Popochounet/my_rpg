/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the color config of a shape
*/
#include "../include/shape.h"

// change the inner color of a shape
void set_color_in_shape(shape_t * shape, sfColor color)
{
    shape->color_in = color;
    if (shape->type == RECT) {
        sfRectangleShape_setFillColor(
                (sfRectangleShape *)(shape->shape), color);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setFillColor(
                (sfCircleShape *)(shape->shape), color);
    }
}

// change the color of the outline of a shape
void set_color_out_shape(shape_t * shape, sfColor color)
{
    shape->color_out = color;
    if (shape->type == RECT) {
        sfRectangleShape_setOutlineColor(
                (sfRectangleShape *)(shape->shape), color);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setOutlineColor(
                (sfCircleShape *)(shape->shape), color);
    }
}

// change the thickness of the outline of a shape
void set_thick_shape(shape_t * shape, int thick)
{
    shape->thick = thick;
    if (shape->type == RECT) {
        sfRectangleShape_setOutlineThickness(
                (sfRectangleShape *)(shape->shape), thick);
    } if (shape->type == CIRCLE) {
        sfCircleShape_setOutlineThickness(
                (sfCircleShape *)(shape->shape), thick);
    }
}

// change inner color, outline color and outline thickness of a shape
void set_attributes_shape(shape_t * shape, sfColor color_in,
                        sfColor color_out, int thick)
{
    set_color_in_shape(shape, color_in);
    set_color_out_shape(shape, color_out);
    set_thick_shape(shape, thick);
}
