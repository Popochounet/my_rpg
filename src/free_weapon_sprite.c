/*
** EPITECH PROJECT, 2023
** free_weapon_sprite.c
** File description:
** -> Frees a weapon sprite
*/

#include <my_rpg.h>

void free_weapon_sprite(draw_t **weapon)
{
    RETURN_IF(!weapon);
    for (unsigned i = 0; i < NB_WEAPON; i++) {
        FREE_IF_ALLOCATED(weapon[i], free_single_draw);
    }
    FREE_IF_ALLOCATED(weapon, free);
}
