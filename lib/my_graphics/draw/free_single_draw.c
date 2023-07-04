/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a specific draw struct
*/
#include "../include/draw.h"

void free_single_draw(draw_t * draw)
{
    switch (draw->type) {
        case SHAPE:
            free_shape((shape_t *)(draw->drawable));
        break;
        case SPRITE:
            free_sprite((sprite_t *)(draw->drawable));
        break;
        case TEXT:
            free_text((text_t *)(draw->drawable));
        break;
        default: break;
    } if (draw->data != NULL) {
        free(draw->data);
    }
    free(draw);
}
