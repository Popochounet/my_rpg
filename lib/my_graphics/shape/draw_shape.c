/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a shape to layer
*/
#include "../include/shape.h"

void draw_shape(sfRenderTexture * texture, shape_t * shape)
{
    if (shape->type == RECT) {
        sfRenderTexture_drawRectangleShape(texture,
                                    (sfRectangleShape *)(shape->shape), NULL);
    }
    if (shape->type == CIRCLE) {
        sfRenderTexture_drawCircleShape(texture,
                                    (sfCircleShape *)(shape->shape), NULL);
    }
}
