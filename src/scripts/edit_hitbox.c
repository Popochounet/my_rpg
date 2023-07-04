/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_append.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void edit_hitbox(window_t * wd)
{
    draw_t * core = wd->core->draw;
    change_hitbox_by_id(core, 60, set_rectangle(20, 140, 300, 40));
    change_hitbox_by_id(core, 66, set_rectangle(0, 0, 102, 1152));
    change_hitbox_by_id(core, 65, set_rectangle(24, 0, 64, 64));
}
