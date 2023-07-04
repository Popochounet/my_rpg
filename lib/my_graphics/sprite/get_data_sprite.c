/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that get information from actual state of a sprite
*/
#include "../include/sprite.h"

// get the position of a sprite
sfVector2f get_position_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getPosition((sfSprite *)(sprite->sprite));
    return vect;
}

// get the rotation of a sprite
float get_rotation_sprite(sprite_t * sprite)
{
    float angle = 0.f;
    angle = sfSprite_getRotation((sfSprite *)(sprite->sprite));
    return angle;
}

// get the scale of a sprite from its initial size
sfVector2f get_scale_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getScale((sfSprite *)(sprite->sprite));
    return vect;
}

// get the origin of a sprite
sfVector2f get_origin_sprite(sprite_t * sprite)
{
    sfVector2f vect = set_2vector(0.f, 0.f);
    vect = sfSprite_getOrigin((sfSprite *)(sprite->sprite));
    return vect;
}
