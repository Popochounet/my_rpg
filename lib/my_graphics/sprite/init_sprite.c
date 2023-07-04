/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a sprite struct
*/
#include "../include/sprite.h"

sprite_t * init_sprite(void)
{
    sprite_t * sprite = malloc(sizeof(sprite_t));
    sprite->sprite = sfSprite_create();
    sprite->texture = NULL;
    sprite->idle_rect = set_rectangle(0, 0, 0, 0);
    sprite->anim_rect = set_rectangle(0, 0, 0, 0);
    sprite->animated = false;
    sprite->loop = false;
    sprite->nb_frame = 0;
    sprite->current = 0;
    return sprite;
}
