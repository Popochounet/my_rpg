/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** update.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

bool check_pos(draw_t *draw, window_t *wd)
{
    if (intersect_with_map(draw, wd->core->draw)) {
        return true;
    }
    return false;
}

void move_player_bis(sfVector2f move, player_t *player)
{
    sfVector2f dir;
    dir.x = move.x > 0 ? 1 : move.x < 0 ? -1 : 0;
    dir.y = move.y > 0 ? 1 : move.y < 0 ? -1 : 0;
    move.x = 0; move.y = 0;
    move.x += dir.x == -1 ? player->stat.speed / 100 : 0;
    move.x -= dir.x == 1 ? player->stat.speed / 100 : 0;
    move.y += dir.y == -1 ? player->stat.speed / 100 : 0;
    move.y -= dir.y == 1 ? player->stat.speed / 100 : 0;
    move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
    move_draw(player->draw, set_2vector(move.x, move.y));
}

sfVector2f move_player(player_t *player, window_t *wd)
{
    sfVector2f move = {0.f, 0.f};
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move.x -= player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move.x += player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move.y -= player->stat.speed / 100;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move.y += player->stat.speed / 100;
    move.y != 0 && move.x != 0 ? move.x /= 1.33, move.y /= 1.33 : 0;
    move_draw(player->draw, set_2vector(move.x, move.y));
    if ((move.x != 0 || move.y != 0) && check_pos(player->draw, wd)) {
        move_player_bis(move, player);
        move.x = 0; move.y = 0;
    }
    set_anim_mob(player->draw, move, &player->dir);
    return move;
}

void update_attack_cl(player_t *player)
{
    float time = sfTime_asSeconds
    (sfClock_getElapsedTime(player->clock));
    if (time <= player->weapon->cooldown)
    set_size_draw(player->cooldown,
    set_2vector(player->cooldown->data->size.x, -160 *
    (time / player->weapon->cooldown)));
    if (time > player->weapon->cooldown)
    set_size_draw(player->cooldown,
    set_2vector(player->cooldown->data->size.x , -160));
}

void update(crowd_t *crowd, window_t *wd)
{
    sfVector2f move = move_player(crowd->player, wd);
    sfVector3f spritePosition = get_position_draw(crowd->player->draw);
    if (move.x != 0 || move.y != 0)
        move_range(crowd->player, move, crowd->player->weapon);
    crowd->player->nb_allied = 0;
    for (int i = 0; i < CROWD_SIZE; i++) {
        sfVector3f pos_tmp = get_position_draw(crowd->cop[i]->draw);
        update_cop(crowd->cop[i], crowd, spritePosition);
        if (crowd->cop[i]->draw->data->position.x < 3200 &&
        check_pos(crowd->cop[i]->draw, wd)) {
            set_pos_draw(crowd->cop[i]->draw, pos_tmp);
            set_pos_draw(crowd->cop[i]->hp.fill, set_3vector(pos_tmp.x,
            pos_tmp.y - 65, 1));
        }
        update_mob(crowd->mob[i], crowd, move, wd);
        crowd->player->nb_allied += crowd->mob[i]->in_mob == true ? 1 : 0;
    }
    update_cop(crowd->boss, crowd, spritePosition);
    attack(crowd);
    update_attack_cl(crowd->player);
}
