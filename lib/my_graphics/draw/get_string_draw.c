/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that enable animation for draw type sprite
*/
#include "../include/draw.h"

const char * get_string_draw(draw_t * draw)
{
    if (draw->type != TEXT) {
        return NULL;
    }
    return get_string_text((text_t *)(draw->drawable));
}
