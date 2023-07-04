/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that get information from a draw
*/
#include "../include/draw.h"

// get the actual position of the draw
sfVector3f get_position_draw(draw_t * draw)
{
    return draw->data->position;
}

// get the actual size of the draw
sfVector2f get_size_draw(draw_t * draw)
{
    return draw->data->size;
}

// get the actual rotation of the draw
float get_rotation_draw(draw_t * draw)
{
    return draw->data->angle;
}

// get the actual scale of the draw compared to its initiale size
sfVector2f get_scale_draw(draw_t * draw)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    switch (draw->type) {
        case SHAPE:
            vect = get_scale_shape((shape_t *)(draw->drawable));
        break;
        case SPRITE:
            vect = get_scale_sprite((sprite_t *)(draw->drawable));
        break;
        case TEXT:
            vect = get_scale_text((text_t *)(draw->drawable));
        break;
        default: break;
    }
    return vect;
}

// get the coordinates of the origin of the draw
sfVector2f get_origin_draw(draw_t * draw)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    switch (draw->type) {
        case SHAPE:
            vect = get_origin_shape((shape_t *)(draw->drawable));
        break;
        case SPRITE:
            vect = get_origin_sprite((sprite_t *)(draw->drawable));
        break;
        case TEXT:
            vect = get_origin_text((text_t *)(draw->drawable));
        break;
        default: break;
    }
    return vect;
}
