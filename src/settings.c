/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** settings.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

draw_t** init_setting_titles(layer_t* layer)
{
    draw_t** titles = malloc(sizeof(draw_t*) * 3);
    char *name[3] = {"VOLUME", "Musique\n\nSons", "RESOLUTION"};
    sfVector3f pos[3] = {set_3vector(250, 250, 0), set_3vector(100, 390, 0),
        set_3vector(1400, 250, 0)};
    text_t* txt = NULL;
    data_t* data = NULL;
    for (int i = 0; i < 3; i++) {
        txt = create_text(name[i], NULL, sfBlack);
        data = create_data(pos[i], set_2vector(0, i == 1 ? 30 : 50), 0);
        titles[i] = create_draw(txt, TEXT, data);
        set_thick_draw(titles[i], 2);
        append_draw_layer(layer, titles[i]);
        set_color_out_draw(titles[i], sfWhite);
    }
    return titles;
}

menu_cat_t* init_settings(list_button_t** all_btn, layer_t* spl)
{
    menu_cat_t* set = malloc(sizeof(menu_cat_t));
    sfVector2f s[2] = {set_2vector(300, 75), set_2vector(200, 75)};
    float val[4] = {0, 100, 100, 75};
    char* name[6] = {"  MANIF PLANIFIEE", "FULLSCREEN", "1920x1080", "1280x720",
        "960x540", "640x360"};
    set->menu_cat_l = create_layer(set_2vector(1920, 1080), NULL);
    set->title = init_setting_titles(set->menu_cat_l);
    set->btn = malloc(sizeof(button_s_t*) * 6);
    set->btn[0] = set_button(all_btn, name[0], set_3vector(100, 900, 0), s[0]);
    set->btn[0] = append_button_layer(set->menu_cat_l, set->btn[0]);
    for (int i = 1; i < 6; i++) {
        set->btn[i] = set_button(all_btn, name[i],
        set_3vector(1500, 300 + i * 100, 0), s[1]);
        set->btn[i] = append_button_layer(set->menu_cat_l, set->btn[i]);
    }
    set->s_btn = set_sliding_button(all_btn, 2, set_3vector(300, 400, 0), val);
    set->s_btn = append_s_button_layer(set->menu_cat_l, set->s_btn, 2);
    append_layer(spl, set->menu_cat_l);
    switch_layer_show(set->menu_cat_l);
    return set;
}

void settings_core(window_t* wd, game_src_t* g_src, button_s_t* set_btn,
    layer_t* layer_to_switch)
{
    if (IS_RELEASED(set_btn) || IS_RELEASED(g_src->menu->settings->btn[0])) {
        switch_layer_show(g_src->menu->settings->menu_cat_l);
        switch_layer_show(layer_to_switch);
        switch_layer_show(g_src->menu->bg_l);
        set_btn->state = NONE;
        g_src->menu->settings->btn[0]->state = NONE;
    }
    if (IS_PRESSED(g_src->menu->settings->s_btn[0]->btn)) {
        g_src->audio.bgm_volume =
        g_src->menu->settings->s_btn[0]->value(g_src->menu->settings->s_btn[0]);
        audio_update_volume(&g_src->audio);
    }
    if (IS_RELEASED(g_src->menu->settings->s_btn[1]->btn)) {
        g_src->audio.sfx_volume =
        g_src->menu->settings->s_btn[1]->value(g_src->menu->settings->s_btn[1]);
        audio_update_volume(&g_src->audio);
        audio_play_sfx(&g_src->audio, SFX_QUEST);
        g_src->menu->settings->s_btn[1]->btn->state = NONE;
    }
    resolutions(wd, g_src->menu->settings);
}
