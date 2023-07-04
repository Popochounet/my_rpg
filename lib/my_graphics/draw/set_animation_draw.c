/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that enable animation for draw type sprite
*/
#include "../include/draw.h"

void set_anim_rect_draw(draw_t * draw, sfIntRect rect)
{
    if (draw->type != SPRITE) {
        return;
    }
    set_anim_rect_sprite((sprite_t *)(draw->drawable), rect);
}

void switch_animation_draw(draw_t * draw)
{
    if (draw->type != SPRITE) {
        return;
    }
    switch_animation_sprite((sprite_t *)(draw->drawable));
}

void switch_loop_draw(draw_t * draw)
{
    if (draw->type != SPRITE) {
        return;
    }
    switch_loop_sprite((sprite_t *)(draw->drawable));
}

void animation_off_draw(draw_t * draw)
{
    if (draw->type != SPRITE) {
        return;
    }
    animation_off_sprite((sprite_t *)(draw->drawable));
}

void set_animation_draw(draw_t * draw, sfIntRect rect,
                            int nb_frame, bool loop)
{
    if (draw->type != SPRITE) {
        return;
    }
    set_animation_sprite((sprite_t *)(draw->drawable), rect, nb_frame, loop);
}
