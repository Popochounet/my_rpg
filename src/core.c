/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void stat_interaction(stat_t* stat, interface_t* stat_ui)
{
    if (!stat->exp_point)
        return;
    for (int i = 0; i < NB_STAT - 2; i++) {
        stat_ui->stat_btns[i]->rect->show = true;
        stat_ui->stat_btns[i]->name->show = true;
        if (IS_RELEASED(stat_ui->stat_btns[i])) {
            stat_ui->stat_btns[i]->state = NONE;
            update_stat(stat, i, stat_ui);
            return;
        }
    }
}

void refresh(window_t *wd, game_src_t *g_src, sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.01) {
        actualize_window(wd);
        sfClock_restart(clock);
    }
    sfVector3f pos = get_position_draw(g_src->game->crowd->player->draw);
    view_center(wd, set_2vector(pos.x, pos.y));
}

int game_core(window_t* wd, game_src_t* g_src, sfClock *clock)
{
    if (g_src->game->crowd->player->hp.fill->data->size.x <= 0) {
        refresh(wd, g_src, clock);
        free_crowd(g_src->game->crowd);
        g_src->game->crowd = NULL;
        audio_control_bgm(&g_src->audio, AUDIO_STOP);
        countryball_49_3(&g_src->audio);
        return 1;
    }
    crowd(wd, g_src->game->crowd, g_src->game->stat_ui, g_src->audio);
    if (g_src->game->crowd->boss->dead == true) {
        win_pop_up();
        return 1;
    }
    float hp_tmp = g_src->game->crowd->player->stat.hp;
    stat_interaction(&g_src->game->crowd->player->stat, g_src->game->stat_ui);
    if (g_src->game->crowd->player->stat.hp > hp_tmp)
    set_size_draw(g_src->game->crowd->player->hp.fill, set_2vector
    (g_src->game->crowd->player->hp.fill->data->size.x + 40,
    g_src->game->crowd->player->hp.fill->data->size.y));
    return 0;
}

void game(window_t* wd, game_src_t* g_src)
{
    sfClock * clock = sfClock_create();

    wd->splash->show = false;
    for (sfEvent evt;
        sfRenderWindow_isOpen(wd->window) && !g_src->menu->show;) {
        while (sfRenderWindow_pollEvent(wd->window, &evt))
            analyse_events(wd, evt, g_src);
        if (g_src->game->pause_menu->show) {
            pause_menu(wd, g_src);
            continue;
        }
        if (game_core(wd, g_src, clock)) {
            g_src->menu->show = true;
            continue;
        }
        refresh(wd, g_src, clock);
    }
    sfClock_destroy(clock);
}

void core(window_t** wd, game_src_t** g_src)
{
    while (sfRenderWindow_isOpen((*wd)->window)) {
        if ((*g_src)->menu->show) {
            (*wd)->splash->show = true;
            audio_set_active_bgm(&(*g_src)->audio, BGM_MENU, 1);
            menu(*wd, *g_src);
            continue;
        }
        if (IS_RELEASED((*g_src)->menu->b_resume)) {
            (*g_src)->menu->b_resume->state = NONE;
            (*g_src)->tuto = false;
        }
        audio_set_active_bgm(&(*g_src)->audio, BGM_MAIN, 1);
        if ((*g_src)->tuto)
            tuto(*wd, *g_src);
        game(*wd, *g_src);
        if ((*g_src)->menu->show)
            restart(wd, g_src);
    }
}
