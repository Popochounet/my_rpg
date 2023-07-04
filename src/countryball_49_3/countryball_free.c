/*
** EPITECH PROJECT, 2023
** countryball_free.c
** File description:
** -> Frees countryball animation
*/

#include <my_macros.h>
#include <countryball.h>

void countryball_free(countryball_t *countryball)
{
    RETURN_IF(!countryball);
    FREE_IF_ALLOCATED(countryball->window, sfRenderWindow_destroy);
    FREE_IF_ALLOCATED(countryball->spritesheet, sfTexture_destroy);
    FREE_IF_ALLOCATED(countryball->sprite, sfSprite_destroy);
    FREE_IF_ALLOCATED(countryball->clock, sfClock_destroy);
    FREE_IF_ALLOCATED(countryball->lose_text, sfText_destroy);
    FREE_IF_ALLOCATED(countryball->font, sfFont_destroy);
}
