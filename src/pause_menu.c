/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** pause_menu.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void append_pause_button_layer(pause_t* pause)
{
    append_button_layer(pause->pause_l, pause->b_resume);
    append_button_layer(pause->pause_l, pause->b_save);
    append_button_layer(pause->pause_l, pause->b_load);
    append_button_layer(pause->pause_l, pause->b_settings);
    append_button_layer(pause->pause_l, pause->b_menu);
    append_button_layer(pause->pause_l, pause->b_quit);
    append_button_layer(pause->pause_l, pause->b_player);
}

pause_t* set_pause_btn(window_t* wd, list_button_t**btns)
{
    pause_t* pause = malloc(sizeof(pause_t));
    sfVector2f size = set_2vector(300, 75);
    pause->b_resume = set_button(btns, "REPRENDRE LA\nLUTTE",
        set_3vector(800, 150, 0), size);
    pause->b_save = set_button(btns, "SAUVEGARDER\nVOS EXPLOITS",
        set_3vector(800, 400, 0), size);
    pause->b_load = set_button(btns, "CHARGER\nVOS EXPLOITS",
        set_3vector(800, 500, 0), size);
    pause->b_settings = set_button(btns, "PLANIFICATION\n(tardive)",
        set_3vector(800, 750, 0), size);
    pause->b_menu = set_button(btns, "RETOUR A LA CASE\nDEPART",
        set_3vector(800, 900, 0), size);
    pause->b_quit = set_button(btns, "ABANDONNER",
        set_3vector(1500, 900, 0), size);
    pause->b_player = set_button(btns, "GESTION DE TON\nMANIFESTANT",
        set_3vector(100, 150, 0), size);
    return pause;
}

pause_t* init_pause_menu(window_t* wd, list_button_t** btns, game_src_t* g_src)
{
    pause_t* pause = set_pause_btn(wd, btns);
    pause->show = false;
    pause->pause_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    append_pause_button_layer(pause);
    append_layer(wd->splash, pause->pause_l);
    pause->settings = g_src->menu->settings;
    pause->player = init_management(wd, btns);
    return pause;
}

void pause_core(window_t* wd, game_src_t* g_src)
{
    if (IS_RELEASED(g_src->game->pause_menu->b_quit))
        sfRenderWindow_close(wd->window);
    if (IS_RELEASED(g_src->game->pause_menu->b_resume)) {
        g_src->game->pause_menu->show = false;
        g_src->game->pause_menu->b_resume->state = NONE;
    }
    if (IS_RELEASED(g_src->game->pause_menu->b_menu)) {
        g_src->game->pause_menu->show = false;
        g_src->menu->show = true;
    }
    save_and_load(g_src);
    player_management_core(wd, g_src, g_src->game->pause_menu->player);
    settings_core(wd, g_src, g_src->game->pause_menu->b_settings,
        g_src->game->pause_menu->pause_l);
}

void pause_menu(window_t* wd, game_src_t* g_src)
{
    g_src->game->pause_menu->pause_l->show = true;
    wd->splash->show = true;
    audio_set_active_bgm(&g_src->audio, BGM_MENU, 1);
    audio_set_bgm_pitch(&g_src->audio, 1.5);
    for (sfEvent pause_evt; sfRenderWindow_isOpen(wd->window) &&
        g_src->game->pause_menu->show;) {
        move_splash(wd, 0);
        while (sfRenderWindow_pollEvent(wd->window, &pause_evt))
            analyse_events(wd, pause_evt, g_src);
        pause_core(wd, g_src);
        draw_layers(wd->window, wd->splash);
        sfRenderWindow_display(wd->window);
    }
    g_src->game->pause_menu->pause_l->show = false;
    wd->splash->show = false;
    audio_set_bgm_pitch(&g_src->audio, 1);
    audio_set_active_bgm(&g_src->audio, BGM_MAIN, 1);
}
