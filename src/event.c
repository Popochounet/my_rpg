/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** event.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfBool switch_bool(sfBool bool_value)
{
    return bool_value == true ? false : true;
}

void key_pressed(sfRenderWindow* wd, sfKeyEvent evt, game_src_t* g_src)
{
    switch (evt.code) {
    case sfKeyEscape:
        if (g_src->menu->show) {
            sfRenderWindow_close(wd);
            break;
        }
        g_src->game->pause_menu->show =
            switch_bool(g_src->game->pause_menu->show);
        update_stat_ui(g_src->game->crowd->player->stat, g_src->game->stat_ui);
        update_stat_ui(g_src->game->crowd->player->stat,
        g_src->game->pause_menu->player->other[0]);
        g_src->game->pause_menu->settings->menu_cat_l->show = false;
        g_src->game->pause_menu->player->menu_cat_l->show = false;
        g_src->menu->bg_l->show = false;
        break;
    default:
        break;
    }
}

void wheel_scrolled(window_t* wd, sfEvent event, game_src_t *g_src)
{
    if (!wd->splash->show) {
        g_src->game->crowd->player->weapon =
        select_weapon(g_src->game->all_weapons,
        g_src->game->crowd->player->weapon, event.mouseWheelScroll.delta);
        update_weapon_ui(g_src->game->all_weapons, g_src->game->crowd->player,
        g_src->game->pause_menu->player->other[1]);
    }
}

void analyse_events(window_t* wd, sfEvent event, game_src_t *g_src)
{
    change_mouse_from_resolution(&event, wd->size);
    switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(wd->window); break;
        case sfEvtKeyPressed:
            key_pressed(wd->window, event.key, g_src); break;
        case sfEvtMouseButtonPressed:
            mouse_button_pressed(wd, event.mouseButton, g_src); break;
        case sfEvtMouseButtonReleased:
            mouse_button_released(wd->window, event.mouseButton,
                g_src->all_btn); break;
        case sfEvtMouseMoved:
            mouse_moved(event.mouseMove, g_src); break;
        case sfEvtMouseWheelScrolled:
            wheel_scrolled(wd, event, g_src); break;
        default: break;
    }
}
