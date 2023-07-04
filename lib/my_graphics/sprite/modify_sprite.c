/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the sprite
*/
#include "../include/sprite.h"

// move the sprite of the given offset
void move_sprite(sprite_t * sprite, sfVector2f offset)
{
    sfSprite_move(sprite->sprite, offset);
}

// scale the size of the sprite
void scale_sprite(sprite_t * sprite, sfVector2f scale)
{
    sfSprite_scale(sprite->sprite, scale);
}

// rotate the sprite of the given angle
void rotate_sprite(sprite_t * sprite, float angle)
{
    sfSprite_rotate(sprite->sprite, angle);
}

// move, scale and rotate the sprite with the parameters
void modify_sprite(sprite_t * sprite, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    move_sprite(sprite, offset);
    scale_sprite(sprite, scale);
    rotate_sprite(sprite, angle);
}
