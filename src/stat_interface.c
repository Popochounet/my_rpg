/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** stat_interface.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

static bool update_stat_ui_text_values
(interface_t *stat_ui, const int values[6])
{
    bool status = true;

    for (stat_list_t i = 0; status && i < STAT_MAX; i++) {
        FREE_IF_ALLOCATED(stat_ui->stat_values[i], free);
        status &= (stat_ui->stat_values[i] = my_itoa(values[i])) != NULL;
        if (!status) {
            break;
        }
        set_string_draw(stat_ui->stat_nb[i], stat_ui->stat_values[i]);
    }
    for (stat_list_t i = 0; status && i < STAT_MAX; i++) {
        FREE_IF_ALLOCATED(stat_ui->stat_values[i], free);
    }
    return status;
}

void update_stat_ui(stat_t stat, interface_t* stat_ui)
{
    const int values[STAT_MAX] = {
        [STAT_LVL] = stat.level,
        [STAT_EXP] = stat.exp_point,
        [STAT_DMG] = stat.damage,
        [STAT_HP] = stat.hp,
        [STAT_SPD] = stat.speed,
        [STAT_DEF] = stat.defense
    };

    update_stat_ui_text_values(stat_ui, values);
    if (!stat.exp_point) {
        for (int i = 0; i < NB_STAT - 2; i++) {
            stat_ui->stat_btns[i]->rect->show = false;
            stat_ui->stat_btns[i]->name->show = false;
        }
    }
}

void update_stat(stat_t *stat, int type, interface_t* stat_ui)
{
    stat->exp_point -= type > 3 ? -1 : 1;
    stat->damage += type == 0 ? 1 : 0;
    stat->hp += type == 1 ? 5 : 0;
    stat->speed += type == 2 ? 1 : 0;
    stat->defense += type == 3 ? 1 : 0;
    stat->damage -= type == 4 ? 1 : 0;
    stat->hp -= type == 5 ? 5 : 0;
    stat->speed -= type == 6 ? 1 : 0;
    stat->defense -= type == 7 ? 1 : 0;
    update_stat_ui(*stat, stat_ui);
}
