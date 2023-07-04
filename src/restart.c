/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** restart.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void restart(window_t** wd, game_src_t** g_src)
{
    sfVideoMode mode = {WD_WIDTH, WD_HEIGHT, 32};
    free_main(*wd, *g_src);
    *wd = create_window("49:3", mode, NULL);
    edit_hitbox(*wd);
    *g_src = init_game_sources(*wd);
}
