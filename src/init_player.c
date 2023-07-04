/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_player.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

const int CHARACTERS_MAX_BASE_STATS[CHARACTER_MAX][5] = {
    [CHARACTER_RAILWAY_WORKER] = {3,20, 12, 6, 0},
    [CHARACTER_DOCTOR] = {-1, 50, 8, 4, 4},
    [CHARACTER_ART_STUDENT] = {3, 20, 10, 2, 6},
    [CHARACTER_POLITICS_STUDENT] = {1, 21, 10, 12, 0},
    [CHARACTER_PREFECT_SON] = {5, 25, 5, 12, 0},
    [CHARACTER_WORKER] = {5, 25, 5, 5, 5},
    [CHARACTER_TROUBLEMAKER] = {12, 10, 10, 1, 0},
};

void init_stat(stat_t *stat, stat_t* base, character_type_t type)
{
    *base = (stat_t) {
        .damage = CHARACTERS_MAX_BASE_STATS[type][0],
        .defense = CHARACTERS_MAX_BASE_STATS[type][1],
        .speed = CHARACTERS_MAX_BASE_STATS[type][2],
        .hp = CHARACTERS_MAX_BASE_STATS[type][3],
        .level = 1,
        .exp_point = CHARACTERS_MAX_BASE_STATS[type][4],
    };
    *stat = (stat_t) {
        .damage = base->damage,
        .defense = base->defense,
        .speed = base->speed,
        .hp = base->hp,
        .level = base->level,
        .exp_point = base->exp_point,
    };
}

void init_bar(player_t *player, window_t* wd)
{
    data_t *data_hp = create_data(set_3vector(70, 15, 50),
    set_2vector(player->stat.hp * 40, 35), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfGreen, sfBlack, 3);
    init_progress_bar(wd, &player->hp, data_hp, shape_hp);
    data_t *data_exp = create_data(set_3vector(1600, 15, 50),
    set_2vector(0, 35), 0.f);
    shape_t *shape_exp = create_shape(RECT, sfBlue, sfBlack, 3);
    init_progress_bar(wd, &player->exp, data_exp, shape_exp);
    data_t *data_hp_txt = create_data(set_3vector(10, 10, 50),
    set_2vector(0, 35), 0.f);
    data_t *data_exp_txt = create_data(set_3vector(1510, 10, 50),
    set_2vector(0, 35), 0.f);
    text_t *text_hp = create_text("HP", NULL, sfBlack);
    text_t *text_exp = create_text("EXP", NULL, sfBlack);
    draw_t *draw_hp = create_draw(text_hp, TEXT, data_hp_txt);
    draw_t *draw_exp = create_draw(text_exp, TEXT, data_exp_txt);
    append_draw_layer(wd->ui, draw_hp);
    append_draw_layer(wd->ui, draw_exp);
    append_draw_layer(wd->ui, player->hp.fill);
    append_draw_layer(wd->ui, player->exp.fill);
}

void init_hitbox(player_t *player, window_t *wd, data_t *data)
{
    data_t *data_r = create_data(data->position, set_2vector(150, 80), 0.f);
    shape_t *shape_r = create_shape(RECT, sfTransparent, sfBlack, 1);
    player->range = create_draw(shape_r, SHAPE, data_r);
    set_origin_draw(player->range, set_2vector
    (data_r->size.x / 2, data_r->size.y / 2));
    append_draw_layer(wd->core, player->range);
    data_t *data_tmp = create_data(
    set_3vector(50, 990, 0), set_2vector(160, -160), 0);
    shape_t *shape = create_shape(RECT,
    sfColor_fromRGBA(200, 200, 200, 150), sfTransparent, 1);
    player->cooldown = create_draw(shape, SHAPE, data_tmp);
    player->weapon_draw = init_weapon_sprite(wd->ui, false);
    append_draw_layer(wd->ui, player->cooldown);
}

player_t *init_player(window_t* wd, game_t *game, bool resume)
{
    player_t *player = malloc(sizeof(player_t));
    player->type = !resume ? select_character() : 0;
    if (player->type == CHARACTER_NONE || player->type == CHARACTER_ERROR) {
        free(player);
        return NULL;
    }
    player->clock = sfClock_create();
    data_t *data = create_data(set_3vector(1200,
    800, 0), set_2vector(48, 72), 0.f);
    player->draw = init_player_draw(player->type, data);
    set_origin_draw(player->draw, set_2vector(48 / 2, 72 - 5));
    append_draw_layer(wd->core, player->draw);
    set_animation_draw(player->draw, (sfIntRect) {0, 0, 48, 72}, 11, true);
    init_hitbox(player, wd, data);
    init_stat(&player->stat, &player->base, player->type);
    init_bar(player, wd);
    player->draw->id = -88;
    player->dir = DIR_PLAYER_DOWN;
    player->nb_allied = 0;
    return player;
}
