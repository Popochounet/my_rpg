/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** hitbox.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void is_hit(cop_t *cop, player_t *player)
{
    cop->stat.hp -= (player->stat.damage * 4) * player->weapon->dmg;
    set_size_draw(cop->hp.fill, set_2vector
    (cop->hp.fill->data->size.x -
    (player->stat.damage * 4) * player->weapon->dmg,
    cop->hp.fill->data->size.y));
    if (cop->stat.hp <= 0) {
        set_size_draw(cop->hp.fill, set_2vector
        (0, cop->hp.fill->data->size.y));
    }
}

void move_range
(player_t *player, sfVector2f move, weapon_t *weapon)
{
    set_size_draw(player->range, weapon->size_hitbox);
    float offset = weapon->size_hitbox.x / 2;
    move.x = move.x > 0 ? 1 : move.x < 0 ? -1 : 0;
    move.y = move.y > 0 ? 1 : move.y < 0 ? -1 : 0;
    set_angle_draw(player->draw, atan2(move.y, move.x) * 180 / M_PI);
    float rot = get_rotation_draw(player->draw);
    sfVector2f hitboxPosition =
    set_2vector
    (player->draw->data->position.x, player->draw->data->position.y);
    hitboxPosition.x += offset * cos(rot * M_PI / 180);
    hitboxPosition.y += offset * sin(rot * M_PI / 180);
    set_origin_draw(player->range, set_2vector
    (weapon->size_hitbox.x / 2, weapon->size_hitbox.y / 2));
    set_angle_draw(player->range, rot);
    set_angle_draw(player->draw, 0);
    set_pos_draw(player->range,
    set_3vector(hitboxPosition.x, hitboxPosition.y, 0));
}

void knock_back(cop_t *cop, player_t *player, float pw, crowd_t* crowd)
{
    sfVector3f cord = calc_dist(cop->draw, player->draw);
    sfVector2f move;
    move.x = cord.x * pw;
    move.y = cord.y * pw;
    move_draw(cop->hp.fill, move);
    move_draw(cop->draw, move);
    get_sprt_cop(cop->draw, move, &cop->cop_e);
    if (cop == crowd->boss)
        get_sprt_boss(crowd->boss->draw, move, &cop->cop_e);
}

void check_hitbox(cop_t *cop, player_t* player, crowd_t* crowd)
{
    if (cop->dead != true &&
    check_collision(cop->draw, player->range)) {
        is_hit(cop, player);
        knock_back(cop, player,
        player->weapon->knockback, crowd);
        if (cop->hp.fill->data->size.x <= 0) {
            set_size_draw(player->exp.fill,
            set_2vector(
            get_size_draw(player->exp.fill).x +
            ((20  - player->stat.level) *
            (rand_move() + 2)),
            get_size_draw(player->exp.fill).y));
            cop->dead = true;
        }
    }
}

void attack(crowd_t *crowd)
{
    const bool is_attack = sfMouse_isButtonPressed(sfMouseLeft) ||
        sfKeyboard_isKeyPressed(sfKeySpace);

    if (is_attack && sfTime_asSeconds(
        sfClock_getElapsedTime(crowd->player->clock)) >
        crowd->player->weapon->cooldown) {
        sfClock_restart(crowd->player->clock);
        for (int i = 0; i < CROWD_SIZE; i++)
            check_hitbox(crowd->cop[i], crowd->player, crowd);
        check_hitbox(crowd->boss, crowd->player, crowd);
    }
}
