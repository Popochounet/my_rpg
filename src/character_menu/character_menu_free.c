/*
** EPITECH PROJECT, 2023
** character_menu_free.c
** File description:
** -> Frees character menu
*/

#include <my_macros.h>
#include <character_menu.h>

void character_menu_free(character_menu_t *menu)
{
    RETURN_IF(!menu);
    FREE_IF_ALLOCATED(menu->clock, sfClock_destroy);
    FREE_IF_ALLOCATED(menu->font, sfFont_destroy);
    FREE_IF_ALLOCATED(menu->window, sfRenderWindow_destroy);
    for (unsigned i = 0; i < N_CHARACTERS; i++) {
        FREE_IF_ALLOCATED(menu->descriptions[i], sfText_destroy);
    }
    for (unsigned i = 0; i < menu->allocated_buttons; i++) {
        free_button(&menu->buttons[i]);
    }
}
