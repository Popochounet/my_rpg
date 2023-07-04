/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** management_interaction.c
*/

#include <my_rpg.h>
#include <my_graphics.h>


void weapon_interaction_p_man(weapon_t** all_weapons, player_t* player,
    interface_t* inv_ui)
{
    if (IS_RELEASED(inv_ui->stat_btns[0])) {
        inv_ui->stat_btns[0]->state = NONE;
        player->weapon = select_weapon(all_weapons, player->weapon, -1);
        update_weapon_ui(all_weapons, player, inv_ui);
    }
    if (IS_RELEASED(inv_ui->stat_btns[1])) {
        inv_ui->stat_btns[1]->state = NONE;
        player->weapon = select_weapon(all_weapons, player->weapon, 1);
        update_weapon_ui(all_weapons, player, inv_ui);
    }
}

bool cap_stat(stat_t stat, stat_t base, interface_t* stat_ui, int i)
{
    int cap = i < 4 && !stat.exp_point ? true : false;
    cap = cap || (i == 4 && stat.damage == base.damage) ? true : false;
    cap = cap || (i == 5 && stat.hp == base.hp) ? true : false;
    cap = cap || (i == 6 && stat.speed == base.speed) ? true : false;
    cap = cap || (i == 7 && stat.defense == base.defense) ? true : false;
    return cap;
}

void stat_interaction_p_man(stat_t* stat, stat_t base, interface_t* stat_ui)
{
    for (int i = 0; i < (NB_STAT - 2) * 2; i++) {
        if (cap_stat(*stat, base, stat_ui, i)) {
            stat_ui->stat_btns[i]->rect->show = false;
            stat_ui->stat_btns[i]->name->show = false;
        } else {
            stat_ui->stat_btns[i]->rect->show = true;
            stat_ui->stat_btns[i]->name->show = true;
        }
        if (IS_RELEASED(stat_ui->stat_btns[i])) {
            stat_ui->stat_btns[i]->state = NONE;
            update_stat(stat, i, stat_ui);
        }
    }
}
