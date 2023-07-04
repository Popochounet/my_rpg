/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that get the bounds of a draw
*/
#include "../include/draw.h"

// get the bounds in the geometrical inner frame of the draw
sfFloatRect get_local_bounds_draw(draw_t * draw)
{
    sfFloatRect rect; rect.top = 0.f; rect.left = 0.f;
    rect.width = 0.f; rect.height = 0.f;
    switch (draw->type) {
        case SHAPE: shape_t * shape = (shape_t *)(draw->drawable);
            if (shape->type == CIRCLE) {
                rect = sfCircleShape_getLocalBounds(
                                        (sfCircleShape *)(shape->shape));
            } if (shape->type == RECT) {
                rect = sfRectangleShape_getLocalBounds(
                                        (sfRectangleShape *)(shape->shape));
            }
        break; case SPRITE:
            rect = sfSprite_getLocalBounds(
                                    ((sprite_t *)(draw->drawable))->sprite);
        break; case TEXT:
            rect = sfText_getLocalBounds(
                                    ((text_t *)(draw->drawable))->text);
        break; default: break;
    } return rect;
}

// get the bounds in the classic geometrical frame
sfFloatRect get_global_bounds_draw(draw_t * draw)
{
    sfFloatRect rect; rect.top = 0.f; rect.left = 0.f;
    rect.width = 0.f; rect.height = 0.f;
    switch (draw->type) {
        case SHAPE: shape_t * shape = (shape_t *)(draw->drawable);
            if (shape->type == CIRCLE) {
                rect = sfCircleShape_getGlobalBounds(
                                        (sfCircleShape *)(shape->shape));
            } if (shape->type == RECT) {
                rect = sfRectangleShape_getGlobalBounds(
                                        (sfRectangleShape *)(shape->shape));
            }
        break; case SPRITE:
            rect = sfSprite_getGlobalBounds(
                                    ((sprite_t *)(draw->drawable))->sprite);
        break; case TEXT:
            rect = sfText_getGlobalBounds(
                                    ((text_t *)(draw->drawable))->text);
        break; default: break;
    } return rect;
}
