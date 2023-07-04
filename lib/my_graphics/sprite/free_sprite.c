/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a sprite struct
*/
#include "../include/sprite.h"

void free_sprite(sprite_t * sprite)
{
    if (sprite == NULL)
        return;
    if (sprite->sprite != NULL)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture != NULL)
        sfTexture_destroy(sprite->texture);
    free(sprite);
}
