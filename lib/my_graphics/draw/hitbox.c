/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the draw
*/
#include "../include/draw.h"

void change_hitbox(draw_t * draw, sfIntRect hitbox)
{
    draw->hitbox.left += hitbox.left;
    draw->hitbox.top += hitbox.top;
    draw->hitbox.width = hitbox.width;
    draw->hitbox.height = hitbox.height;
}

void change_hitbox_by_id(draw_t * draw, int id, sfIntRect hitbox)
{
    while (draw != NULL) {
        if (draw->id == id) {
            change_hitbox(draw, hitbox);
        }
        draw = draw->next;
    }
}

sfIntRect get_hitbox(draw_t * draw)
{
    return draw->hitbox;
}

sfFloatRect get_f_hitbox(draw_t * draw)
{
    sfFloatRect rect;
    rect.top = (float)draw->hitbox.top;
    rect.left = (float)draw->hitbox.left;
    rect.width = (float)draw->hitbox.width;
    rect.height = (float)draw->hitbox.height;
    return rect;
}
