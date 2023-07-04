/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a specific draw to layer
*/
#include "../include/draw.h"

void draw_single_draw(sfRenderTexture * texture, draw_t * draw)
{
    set_data_draw(draw, draw->data);
    if (draw->id < 0) {
        draw->hitbox.left = draw->data->position.x;
        draw->hitbox.top = draw->data->position.y;
    }
    if (!draw->show) {
        return;
    }
    switch (draw->type) {
        case SHAPE:
            draw_shape(texture, (shape_t *)(draw->drawable));
        break;
        case SPRITE:
            draw_sprite(texture, (sprite_t *)(draw->drawable));
        break;
        case TEXT:
            draw_text(texture, (text_t *)(draw->drawable));
        break;
        default: break;
    }
}
