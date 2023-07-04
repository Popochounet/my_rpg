/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_cop.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void init_cop_hp_bar(window_t *wd, cop_t * cop, sfVector2f pos, int tmp)
{
    pos.x += wd->map_size.x / 2 * tmp;
    data_t *data_hp = create_data(set_3vector(pos.x, pos.y - 65, 100),
    set_2vector(80, 10), 0.f);
    shape_t *shape_hp = create_shape(RECT, sfRed, sfBlack, 3);
    init_progress_bar(wd, &cop->hp, data_hp, shape_hp);
    set_origin_draw(cop->hp.fill, (sfVector2f)
    {data_hp->size.x / 2, data_hp->size.y / 2});
    append_draw_layer(wd->core, cop->hp.fill);
    cop->stat = (stat_t) {.damage = 5, .hp = 80, .speed = 5, .defense = 5
        };
}

draw_t *init_cop_draw(window_t* wd, sfVector2f pos, int tmp)
{
    sprite_t *sprite = init_sprite();
    sfTexture *texture = sfTexture_createFromFile
    ("images/spritesheets/crs_spritesheet.png", NULL);
    pos.x += wd->map_size.x / 2 * tmp;
    data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
    set_2vector(64, 72), 0.f);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 64, 72});
    return create_draw(sprite, SPRITE, data);
}

cop_t **init_crowd_cop(window_t* wd)
{
    cop_t **cop = malloc(sizeof(cop_t*) * CROWD_SIZE);
    int tmp = 1;
    for (int i = 0; i < CROWD_SIZE; i++) {
        cop[i] = malloc(sizeof(cop_t));
        cop[i]->dead = false;
        tmp = i == 30 ? 3 : tmp;
        tmp = i == 100 ? 5 : tmp;
        cop[i]->clock = sfClock_create();
        sfVector2f pos = get_random_position(wd);
        cop[i]->draw = init_cop_draw(wd, pos, tmp);
        set_origin_draw(cop[i]->draw, set_2vector
            (64 / 2, 72 - 5));
        append_draw_layer(wd->core, cop[i]->draw);
        set_animation_draw(cop[i]->draw, (sfIntRect) {0, 0, 64, 72}, 3, true);
        init_cop_hp_bar(wd, cop[i], pos, tmp);
        cop[i]->cop_e = DIR_COP_S;
        cop[i]->draw->id = -88;
    }
    return cop;
}
