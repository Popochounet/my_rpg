/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

float calculate_sprite_distance(draw_t *player, draw_t *crowd)
{
    sfFloatRect rect1 = get_global_bounds_draw(player);
    sfFloatRect rect2 = get_global_bounds_draw(crowd);
    float dx = rect2.left - rect1.left;
    float dy = rect2.top - rect1.top;
    return sqrt(dx * dx + dy * dy);
}

sfBool draw_within_thr(draw_t *player, draw_t *crowd, float thr)
{
    float distance = calculate_sprite_distance(player, crowd);
    return distance <= thr;
}

sfBool check_collision(draw_t *player, draw_t *crowd)
{
    sfFloatRect spriteBounds = get_global_bounds_draw(player);
    sfFloatRect crowdBounds = get_global_bounds_draw(crowd);
    return sfFloatRect_intersects(&spriteBounds, &crowdBounds, NULL);
}

void set_anim_mob(draw_t *draw, sfVector2f move, dir_e *dir)
{
    if (move.x == 0 && move.y == 0) {
        set_anim_rect_draw(draw, (sfIntRect) {0, 0, 48, 72});
        return;
    }
    if (move.y < 0 && *dir != DIR_PLAYER_UP) {
        set_anim_rect_draw(draw, (sfIntRect) {528, 0, 48, 72});
        *dir = DIR_PLAYER_UP;
        return;
    } else if (move.y >= 0 && *dir != DIR_PLAYER_DOWN) {
        set_anim_rect_draw(draw, (sfIntRect) {0, 0, 48, 72});
        *dir = DIR_PLAYER_DOWN;
    }
}

void crowd(window_t *wd, crowd_t *crowd, interface_t *stat_ui, audio_t audio)
{
    update(crowd, wd);
    if (crowd->player->exp.fill->data->size.x >= 250) {
        float tmp = crowd->player->exp.fill->data->size.x - 250;
        set_size_draw(crowd->player->exp.fill,
        set_2vector(tmp, crowd->player->exp.fill->data->size.y));
        crowd->player->stat.exp_point += 1;
        crowd->player->stat.level += crowd->player->stat.level < 20 ?
        1 : 0;
        update_stat_ui(crowd->player->stat, stat_ui);
        audio_play_sfx(&audio, SFX_LEVEL_UP);
    }
    if (crowd->player->nb_allied == NB_ALLIED_REQUIRED - 1) {
        set_pos_draw(crowd->boss->draw, set_3vector(4000, 800, 0));
        set_pos_draw(crowd->boss->hp.fill, set_3vector(4000, 650, 100));
    }
}
