/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_cop.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

sfVector3f get_closer_mob(cop_t *cop, crowd_t *crowd)
{
    sfVector3f cord;
    float dist_min = 10000;
    int tmp = 0;
    for (int i = 0; i < CROWD_SIZE; i++) {
        if (crowd->mob[i]->in_mob != OUT)
        continue;
        cord = calc_dist(crowd->mob[i]->draw, cop->draw);
        tmp = dist_min > cord.z ? i : tmp;
        dist_min = dist_min > cord.z ? cord.z : dist_min;
        if (cord.z < 50) {
            crowd->mob[i]->in_mob = DEAD;
            crowd->mob[i]->dir = -1;
        }
    }
    cord = calc_dist(crowd->mob[tmp]->draw, cop->draw);
    return cord;
}

void update_circle_cop
(cop_t *cop, crowd_t *crowd, sfVector3f cop_pos, sfVector3f pos_pl)
{
    sfVector3f cord = calc_dist(crowd->player->draw, cop->draw);
    sfVector2f move;
    if (draw_within_thr(crowd->player->draw, cop->draw, 60) &&
    sfTime_asSeconds(sfClock_getElapsedTime(cop->clock)) > 3
    && get_size_draw(crowd->player->hp.fill).x > 0) {
        sfVector2f size = get_size_draw(crowd->player->hp.fill);
        set_size_draw(crowd->player->hp.fill, set_2vector
        (size.x -(cop->stat.damage - (crowd->player->stat.defense / 50)),
        size.y));
        sfClock_restart(cop->clock);
    }
    sfVector3f cord_mob = get_closer_mob(cop, crowd);
    cord = cord.z < cord_mob.z ? cord : cord_mob;
    move.x = cord.x * (cop->stat.speed / 100);
    move.y = cord.y * (cop->stat.speed / 100);
    move_draw(cop->hp.fill, move);
    move_draw(cop->draw, move);
    get_sprt_cop(cop->draw, move, &cop->cop_e);
    if (cop == crowd->boss)
        get_sprt_boss(crowd->boss->draw, move, &cop->cop_e);
}

void is_dead(cop_t *cop, player_t *player, crowd_t* crowd)
{
    cop->dead = true;
    set_thick_draw(cop->hp.fill, 0);
    sfVector3f cord = calc_dist(player->draw, cop->draw);
    if (cord.z < 400) {
        knock_back(cop, player, (cop->stat.speed / 100), crowd);
        return;
    }
    sfVector2f move = set_2vector(0.03, 0);
    move_draw(cop->draw, move);
    get_sprt_cop(cop->draw, move, &cop->cop_e);
}

void update_cop(cop_t *cop, crowd_t *crowd, sfVector3f spritePosition)
{
    if (cop->draw->data->position.x > 3800) {
        float dir = !cop->dead ? -0.03 : 0.03;
        sfVector2f moved = set_2vector(dir, 0);
        move_draw(cop->hp.fill, moved);
        move_draw(cop->draw, moved);
        return;
    }
    if (cop->stat.hp <= 0) {
        is_dead(cop, crowd->player, crowd);
        return;
    }
    sfVector3f cop_pos = get_position_draw(cop->draw);
    update_circle_cop(cop, crowd, cop_pos, spritePosition);

}
