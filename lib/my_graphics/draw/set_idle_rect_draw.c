/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the default rectangle of a sprite draw
*/
#include "../include/draw.h"

void set_idle_rect_draw(draw_t * draw, sfIntRect rect)
{
    if (draw->type != SPRITE) {
        return;
    }
    set_idle_rect_sprite((sprite_t *)(draw->drawable), rect);
}
