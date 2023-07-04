/*
** EPITECH PROJECT, 2023
** stat_interface_init.c
** File description:
** -> Initializes stat interface
*/

#include <my_rpg.h>

button_s_t* init_stat_interface_bis(int i, list_button_t** a_btn, layer_t* ui)
{
    button_s_t* btn = set_button(a_btn, "+",
    set_3vector(320, 60 + i * 50, 0), set_2vector(25, 25));
    btn = append_button_layer(ui, btn);
    set_size_draw(btn->name, set_2vector(0, 20));
    return btn;
}

void init_stat_ui_values(interface_t *stat_ui)
{
    for (stat_list_t i = 0; i < STAT_MAX; i++) {
        stat_ui->stat_values[i] = NULL;
    }
}

interface_t* init_stat_interface(layer_t* ui, list_button_t** a_btn)
{
    interface_t* stat_ui = malloc(sizeof(interface_t));
    char *name[NB_STAT] = {"LEVEL", "EXP POINT","DEGAT", "PV", "VITESSE",
        "DEFENSE"};
    stat_ui->stat_btns = malloc(sizeof(button_s_t*) * NB_STAT - 2);
    stat_ui->stat_name = malloc(sizeof(draw_t*) * NB_STAT);
    stat_ui->stat_nb = malloc(sizeof(draw_t*) * NB_STAT);
    init_stat_ui_values(stat_ui);
    for (int i = 0; i < NB_STAT; i++) {
        if (i > 1)
            stat_ui->stat_btns[i - 2] = init_stat_interface_bis(i, a_btn, ui);
        stat_ui->stat_name[i] = create_draw(create_text(name[i], NULL, sfBlack),
            TEXT, create_data(set_3vector(20, 50 + i * 50, 0),
            set_2vector(0, !i ? 50 : 35), 0));
        stat_ui->stat_nb[i] = create_draw(create_text("", NULL, sfBlack),
            TEXT, create_data(set_3vector(250, 50 + i * 50, 0),
            set_2vector(0, !i ? 50 : 35), 0));
        append_draw_layer(ui, stat_ui->stat_name[i]);
        append_draw_layer(ui, stat_ui->stat_nb[i]);
    }
    return stat_ui;
}
