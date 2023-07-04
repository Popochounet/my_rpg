/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** p_man_stats.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

draw_t** init_p_man_titles(layer_t* layer)
{
    draw_t** titles = malloc(sizeof(draw_t*) * 4);
    char *name[4] = {"STATS", "INVENTAIRE", "QUETE EN COURS", "Reunir 30 manife"
    "stants pour invoquer le mechant Macrongue et lui faire retirer sa reforme"
    };
    sfVector3f pos[4] = {set_3vector(100, 100, 0), set_3vector(1000, 100, 0),
        set_3vector(100, 800, 0), set_3vector(150, 900, 0)};
    text_t* txt = NULL;
    data_t* data = NULL;
    for (int i = 0; i < 4; i++) {
        txt = create_text(name[i], NULL, i == 3 ? sfYellow : sfBlack);
        data = create_data(pos[i], set_2vector(0, i == 3 ? 30 : 50), 0);
        titles[i] = create_draw(txt, TEXT, data);
        set_thick_draw(titles[i], 2);
        append_draw_layer(layer, titles[i]);
        set_color_out_draw(titles[i], i == 3 ? sfBlack : sfWhite);
    }
    return titles;
}

button_s_t** init_p_man_stat_button(list_button_t** a_btn, layer_t* lyr)
{
    button_s_t** btns = malloc(sizeof(button_s_t*) * (NB_STAT - 2) * 2);
    int i = 0;
    for (; i < NB_STAT - 2; i++) {
        btns[i] = set_button(a_btn, "   +",
        set_3vector(600, 400 + i * 50, 0), set_2vector(50, 25));
        btns[i] = append_button_layer(lyr, btns[i]);
        set_size_draw(btns[i]->name, set_2vector(0, 20));
    }
    for (; i < (NB_STAT - 2) * 2; i++) {
        btns[i] = set_button(a_btn, "   -",
        set_3vector(200, 400 + (i - 4) * 50, 0), set_2vector(50, 25));
        btns[i] = append_button_layer(lyr, btns[i]);
        set_size_draw(btns[i]->name, set_2vector(0, 20));
    }
    return btns;
}

interface_t* init_p_man_stat_ui(layer_t* lyr, list_button_t** a_btn)
{
    interface_t* stat_ui = malloc(sizeof(interface_t));
    char *name[NB_STAT] = {"LEVEL:", "Exp Point:","DEGAT", "PV", "VITESSE",
        "DEFENSE"};
    stat_ui->stat_name = malloc(sizeof(draw_t*) * NB_STAT);
    stat_ui->stat_nb = malloc(sizeof(draw_t*) * NB_STAT);
    stat_ui->stat_btns = init_p_man_stat_button(a_btn, lyr);
    init_stat_ui_values(stat_ui);
    for (int i = 0; i < NB_STAT; i++) {
        stat_ui->stat_name[i] = create_draw(create_text(name[i], NULL, i == 1 ?
            sfYellow : sfBlack), TEXT, create_data(set_3vector(300, !i ?
            250 : 290 + i * 50, 0), set_2vector(0, !i ? 50 : 35), 0));
        stat_ui->stat_nb[i] = create_draw(create_text("", NULL, i == 1 ?
            sfYellow : sfBlack), TEXT, create_data(set_3vector(500,
            !i ? 250 : 290 + i * 50, 0), set_2vector(0, !i ? 50 : 40), 0));
        set_thick_draw(stat_ui->stat_name[i], 2);
        set_thick_draw(stat_ui->stat_nb[i], 2);
        append_draw_layer(lyr, stat_ui->stat_name[i]);
        append_draw_layer(lyr, stat_ui->stat_nb[i]);
    }
    return stat_ui;
}

menu_cat_t* init_management(window_t* wd, list_button_t** a_btns)
{
    menu_cat_t* p_man = malloc(sizeof(menu_cat_t));
    sfVector2f s[2] = {set_2vector(300, 75), set_2vector(200, 75)};
    char* name[1] = {"    MANIFESTANT\n    PLANIFIEE"};
    p_man->menu_cat_l = create_layer(set_2vector(WD_WIDTH, WD_HEIGHT), NULL);
    p_man->title = init_p_man_titles(p_man->menu_cat_l);
    p_man->btn = malloc(sizeof(button_s_t*) * 1);
    for (int i = 0; i < 1; i++) {
        p_man->btn[i] = set_button(a_btns, name[i],
        set_3vector(1500, 900, 0), s[i]);
        p_man->btn[i] = append_button_layer(p_man->menu_cat_l, p_man->btn[i]);
    }
    p_man->other = malloc(sizeof(void*) * 2);
    p_man->other[0] = init_p_man_stat_ui(p_man->menu_cat_l, a_btns);
    p_man->other[1] = init_p_man_inventory(p_man->menu_cat_l, a_btns);
    append_layer(wd->splash->next, p_man->menu_cat_l);
    swap_layer_up(p_man->menu_cat_l);
    p_man->menu_cat_l->show = false;
    return p_man;
}

void player_management_core(window_t* wd, game_src_t* g_src, menu_cat_t* p_man)
{
    if (IS_RELEASED(g_src->game->pause_menu->b_player) ||
        IS_RELEASED(p_man->btn[0])) {
        switch_layer_show(p_man->menu_cat_l);
        switch_layer_show(g_src->menu->bg_l);
        switch_layer_show(g_src->game->pause_menu->pause_l);
        g_src->game->pause_menu->b_player->state = NONE;
        p_man->btn[0]->state = NONE;
        update_stat_ui(g_src->game->crowd->player->stat, g_src->game->stat_ui);
        update_stat_ui(g_src->game->crowd->player->stat, p_man->other[0]);
        update_weapon_ui(g_src->game->all_weapons, g_src->game->crowd->player,
            g_src->game->pause_menu->player->other[1]);
    }
    stat_interaction_p_man(&g_src->game->crowd->player->stat,
        g_src->game->crowd->player->base, p_man->other[0]);
    weapon_interaction_p_man(g_src->game->all_weapons,
        g_src->game->crowd->player, p_man->other[1]);
}
