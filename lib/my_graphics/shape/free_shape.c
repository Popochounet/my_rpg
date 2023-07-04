/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a shape struct
*/
#include "../include/shape.h"

void free_shape(shape_t * shape)
{
    if (shape == NULL)
        return;
    if (shape->type == RECT && shape->shape != NULL) {
        sfRectangleShape_destroy((sfRectangleShape *)(shape->shape));
    }
    if (shape->type == CIRCLE && shape->shape != NULL) {
        sfCircleShape_destroy((sfCircleShape *)(shape->shape));
    }
    free(shape);
}
