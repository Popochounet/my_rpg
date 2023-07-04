/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update_mob.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void place_in_mob(mob_t *mob, player_t *player, window_t *wd)
{
    float angle = (float)(rand() % 360);
    float r = (float)rand() / RAND_MAX * 180;
    sfVector3f newPosition = {
        get_position_draw(player->draw).x + cos(angle) * (r + 60),
        get_position_draw(player->draw).y + sin(angle) * (r + 60),
        0
    };
    mob->in_mob = IN;
    set_pos_draw(mob->draw, newPosition);
    if (check_pos(mob->draw, wd))
        place_in_mob(mob, player, wd);
    if (mob->type == CHARACTER_DOCTOR &&
    player->hp.fill->data->size.x + 50 < player->stat.hp * 40)
        set_size_draw(player->hp.fill, set_2vector(player->hp.fill->data->size.x
        + 50, player->hp.fill->data->size.y));
    else if (mob->type == CHARACTER_DOCTOR &&
    player->hp.fill->data->size.x + 50 >= player->stat.hp * 40)
        set_size_draw(player->hp.fill, set_2vector(player->stat.hp * 40,
        player->hp.fill->data->size.y));
}

void not_in_mob(mob_t *mob, player_t *player, window_t *wd)
{
    sfVector3f pos = get_position_draw(mob->draw);
    sfVector2f move = set_2vector(0, 0);
    move = set_2vector((0.03 * mob->dir), rand_move());
    sfVector3f pos_p = get_position_draw(player->draw);
    float dx = pos_p.x - pos.x;
    float dy = pos_p.y - pos.y;
    float distance = sqrt(dx * dx + dy * dy);
    move_draw(mob->draw, move);
    if (distance < 50.0 && mob->in_mob != DEAD) {
            set_size_draw(player->exp.fill,
        set_2vector(
        get_size_draw(player->exp.fill).x +
        ((20  - player->stat.level) *
        (rand_move() + 2)),
        get_size_draw(player->exp.fill).y));
        place_in_mob(mob, player, wd);
    }
}

void update_mob
(mob_t *mob, crowd_t *crowd, sfVector2f move, window_t *wd)
{
    if (mob->in_mob == OUT || mob->in_mob == DEAD)
        not_in_mob(mob, crowd->player, wd);
    if (mob->in_mob == IN) {
        sfVector3f pos_tmp = get_position_draw(mob->draw);
        move_draw(mob->draw, move);
        set_anim_mob(mob->draw, move, &mob->mov);
        if (check_pos(mob->draw, wd))
            set_pos_draw(mob->draw, pos_tmp);
    }
}
