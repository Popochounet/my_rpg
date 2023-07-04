/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_crowd.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void init_boss_hp_bar(window_t *wd, cop_t * cop, sfVector2f pos)
{
    data_t *data_hp = create_data(set_3vector(pos.x, pos.y - 90, 100),
    set_2vector(600, 35), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfRed, sfBlack, 3);
    init_progress_bar(wd, &cop->hp, data_hp, shape_hp);
    set_origin_draw(cop->hp.fill, (sfVector2f)
    {data_hp->size.x / 2, data_hp->size.y / 2});
    append_draw_layer(wd->core, cop->hp.fill);
    cop->stat = (stat_t) {.damage = 15, .hp = 600, .speed = 3, .defense = 5
    };
}

draw_t *init_boss_draw(window_t* wd, sfVector2f pos)
{
    sprite_t *sprite = init_sprite();
    sfTexture *texture = sfTexture_createFromFile
    ("images/spritesheets/boss_spritesheet.png", NULL);
    data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
    set_2vector(128, 144), 0.f);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 128, 144});
    return create_draw(sprite, SPRITE, data);
}

cop_t* init_boss(window_t* wd)
{
    cop_t* boss = malloc(sizeof(cop_t));
    boss->clock = sfClock_create();
    sfVector2f pos = set_2vector(100000, wd->map_size.y / 2);
    boss->draw = init_boss_draw(wd, pos);
    boss->dead = false;
    set_origin_draw(boss->draw, set_2vector
        (128 / 2, 144 - 10));
    append_draw_layer(wd->core, boss->draw);
    set_animation_draw(boss->draw, (sfIntRect) {0, 0, 128, 144}, 3, true);
    init_boss_hp_bar(wd, boss, pos);
    boss->cop_e = DIR_COP_S;
    boss->dead = false;
    boss->draw->id = -88;
    return boss;
}

bool init_crowd(window_t* wd, list_button_t** a_btn,
    game_src_t* g_src, bool resume)
{
    g_src->game->crowd = malloc(sizeof(crowd_t));
    g_src->game->crowd->player = init_player(wd, g_src->game, resume);
    if (g_src->game->crowd->player == NULL) {
        g_src->game->crowd = NULL;
        free(g_src->game->crowd);
        return false;
    }
    g_src->game->crowd->player->weapon = g_src->game->all_weapons[0];
    update_weapon_ui(g_src->game->all_weapons, g_src->game->crowd->player,
        g_src->game->pause_menu->player->other[1]);
    update_stat_ui(g_src->game->crowd->player->stat, g_src->game->stat_ui);
    append_draw_layer(wd->ui, create_draw(create_shape(RECT,
    sfColor_fromRGBA(220, 220, 220, 100), sfBlack, 3), SHAPE,
    create_data(set_3vector(10, 60, 0), set_2vector(340, 280), 0)));
    g_src->game->crowd->mob = init_crowd_mob(wd);
    g_src->game->crowd->cop = init_crowd_cop(wd);
    g_src->game->crowd->boss = init_boss(wd);
    return true;
}
