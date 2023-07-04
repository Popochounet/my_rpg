/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that set the part of texture to display
*/
#include "../include/sprite.h"

void set_idle_rect_sprite(sprite_t * sprite, sfIntRect rect)
{
    sprite->idle_rect = rect;
}

void set_texture_sprite(sprite_t * sprite, sfTexture * texture, sfIntRect rect)
{
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, texture, sfTrue);
    sprite->idle_rect = rect;
    if (rect.width != 0 && rect.height != 0) {
        sfSprite_setTextureRect(sprite->sprite, rect);
    } else {
        sfSprite_setTexture(sprite->sprite, texture, sfFalse);
    }
}
