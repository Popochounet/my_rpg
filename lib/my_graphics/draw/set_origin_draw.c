/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function set the origin of a draw
*/
#include "../include/draw.h"

void set_origin_draw(draw_t * draw, sfVector2f origin)
{
    switch (draw->type) {
        case SHAPE:
            shape_t * shape = (shape_t *)(draw->drawable);
            if (shape->type == CIRCLE) {
                sfCircleShape_setOrigin((sfCircleShape *)(shape->shape),
                                            origin);
            } if (shape->type == RECT) {
                sfRectangleShape_setOrigin((sfRectangleShape *)(shape->shape),
                                            origin);
            }
        break;
        case SPRITE:
            sfSprite_setOrigin(((sprite_t *)(draw->drawable))->sprite, origin);
        break;
        case TEXT:
            sfText_setOrigin(((text_t *)(draw->drawable))->text, origin);
        break;
        default: break;
    }
}
