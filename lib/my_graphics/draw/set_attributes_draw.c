/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the color config of a draw
** works only for draw type shape & text
*/
#include "../include/draw.h"

// change the inner color of a draw
void set_color_in_draw(draw_t * draw, sfColor color)
{
    switch (draw->type) {
        case SHAPE:
            set_color_in_shape((shape_t *)(draw->drawable), color);
        break;
        case TEXT:
            set_color_in_text((text_t *)(draw->drawable), color);
        break;
        default: break;
    }
}

// change the color of the outline of a draw
void set_color_out_draw(draw_t * draw, sfColor color)
{
    switch (draw->type) {
        case SHAPE:
            set_color_out_shape((shape_t *)(draw->drawable), color);
        break;
        case TEXT:
            set_color_out_text((text_t *)(draw->drawable), color);
        break;
        default: break;
    }
}

// change the thickness of the outline of a draw
void set_thick_draw(draw_t * draw, int thick)
{
    switch (draw->type) {
        case SHAPE:
            set_thick_shape((shape_t *)(draw->drawable), thick);
        break;
        case TEXT:
            set_thick_text((text_t *)(draw->drawable), thick);
        break;
        default: break;
    }
}

// change inner color, outline color and outline thickness of a draw
void set_attributes_draw(draw_t * draw, sfColor color_in,
                        sfColor color_out, int thick)
{
    switch (draw->type) {
        case SHAPE:
            set_attributes_shape((shape_t *)(draw->drawable), color_in,
                                    color_out, thick);
        break;
        case TEXT:
            set_attributes_text((text_t *)(draw->drawable), color_in,
                                    color_out, thick);
        break;
        default: break;
    }
}
