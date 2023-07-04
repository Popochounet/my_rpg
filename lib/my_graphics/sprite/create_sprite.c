/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a sprite struct from parameters
*/
#include "../include/sprite.h"

sprite_t * create_sprite(sfTexture * texture, sfIntRect rect)
{
    sprite_t * sprite = init_sprite();
    set_texture_sprite(sprite, texture, rect);
    return sprite;
}
