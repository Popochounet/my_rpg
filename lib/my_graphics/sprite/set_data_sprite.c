/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** functions that set position and rotation of the sprite
*/
#include "../include/sprite.h"

// set the position of the sprite
void set_pos_sprite(sprite_t * sprite, sfVector3f position)
{
    sfVector2f pos = set_2vector(position.x, position.y);
    sfSprite_setPosition(sprite->sprite, pos);
}

// set the rotation of the sprite
void set_angle_sprite(sprite_t * sprite, float angle)
{
    sfSprite_setRotation(sprite->sprite, angle);
}

// set the position and rotation of the sprite
void set_data_sprite(sprite_t * sprite, data_t * data)
{
    set_pos_sprite(sprite, data->position);
    set_angle_sprite(sprite, data->angle);
}
