/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw sprite to layer
*/
#include "../include/sprite.h"
#include <stdio.h>

void draw_sprite(sfRenderTexture * texture, sprite_t * sprite)
{
    if (!sprite->animated) {
        sfSprite_setTextureRect(sprite->sprite, sprite->idle_rect);
        sfRenderTexture_drawSprite(texture, sprite->sprite, NULL);
        return;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->anim_rect);
    sfRenderTexture_drawSprite(texture, sprite->sprite, NULL);
    if (sprite->current < sprite->nb_frame - 1) {
        sprite->current++;
        sprite->anim_rect = next_rectangle(sprite->anim_rect);
    } else {
        if (sprite->loop) {
            sprite->current = 0;
            sprite->anim_rect.left -= sprite->anim_rect.width *
                                        (sprite->nb_frame - 1);
        } else {
            animation_off_sprite(sprite);
        }
    }
}
