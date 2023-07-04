/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set informations for animation
*/
#include "../include/sprite.h"

// restart animation to frame 0
void set_anim_rect_sprite(sprite_t * sprite, sfIntRect rect)
{
    sprite->anim_rect = rect;
    sprite->current = 0;
}

void switch_animation_sprite(sprite_t * sprite)
{
    if (sprite->animated) {
        sprite->animated = false;
    } else {
        sprite->animated = true;
    }
}

void switch_loop_sprite(sprite_t * sprite)
{
    if (sprite->loop) {
        sprite->loop = false;
    } else {
        sprite->loop = true;
    }
}

void animation_off_sprite(sprite_t * sprite)
{
    sprite->animated = false;
    sprite->loop = false;
    sprite->nb_frame = 0;
    sprite->current = 0;
}

void set_animation_sprite(sprite_t * sprite, sfIntRect rect,
                            int nb_frame, bool loop)
{
    if (rect.width == 0 || rect.height == 0) {
        return;
    }
    sprite->animated = true;
    sprite->loop = loop;
    sprite->anim_rect = rect;
    sprite->nb_frame = nb_frame;
    sprite->current = 0;
}
