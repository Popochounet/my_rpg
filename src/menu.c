/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** menu.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void menu_core(window_t* wd, game_src_t* g_src)
{
    if (IS_RELEASED(g_src->menu->b_resume)) {
        if (!does_save_file_exist() &&
            init_crowd(wd, &g_src->all_btn, g_src, true) &&
            load_from_file(g_src->game->crowd->player)) {
            refresh_player(g_src->game->crowd->player,
            g_src->game->crowd->player->draw->drawable, g_src->game);
            audio_play_sfx(&g_src->audio, SFX_QUEST);
            g_src->menu->show = false;
        } else
            audio_play_sfx(&g_src->audio, SFX_ERROR);
    }
    if (IS_RELEASED(g_src->menu->b_start)) {
        if (init_crowd(wd, &g_src->all_btn, g_src, false))
            g_src->menu->show = false;
        g_src->menu->b_start->state = NONE;
    }
    if (IS_RELEASED(g_src->menu->b_quit))
        sfRenderWindow_close(wd->window);
    settings_core(wd, g_src, g_src->menu->b_settings, g_src->menu->menu_l);
}

void menu(window_t* wd, game_src_t* g_src)
{
    g_src->menu->menu_l->show = true;
    for (sfEvent menu_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->menu->show;) {
        move_splash(wd, 1);
        while (sfRenderWindow_pollEvent(wd->window, &menu_evt))
            analyse_events(wd, menu_evt, g_src);
        menu_core(wd, g_src);
        draw_layers(wd->window, wd->splash);
        sfRenderWindow_display(wd->window);
    }
    g_src->menu->menu_l->show = false;
    wd->splash->show = false;
}
