/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** init_mob.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

draw_t *init_mob_draw(window_t* wd, sfVector2f pos, int tmp, mob_t *mob)
{
    sprite_t *sprite = init_sprite();
    sfTexture *texture = rand_skin(&mob->type);
    pos.x -= wd->map_size.x / 2 * tmp;
    data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
    set_2vector(48, 72), 0.f);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    return create_draw(sprite, SPRITE, data);
}

mob_t **init_crowd_mob(window_t* wd)
{
    int tmp = 1;
    mob_t **mob = malloc(sizeof(cop_t*) * CROWD_SIZE);
    for (int i = 0; i < CROWD_SIZE; i++) {
        mob[i] = malloc(sizeof(mob_t));
        tmp = i == 30 ? 3 : tmp;
        tmp = i == 100 ? 5 : tmp;
        sfVector2f pos = get_random_position(wd);
        mob[i]->draw = init_mob_draw(wd, pos, tmp, mob[i]);
        set_origin_draw(mob[i]->draw, set_2vector
            (48 / 2, 72 - 5));
        set_animation_draw(mob[i]->draw, (sfIntRect) {0, 0, 48, 72}, 11, true);
        append_draw_layer(wd->core, mob[i]->draw);
        mob[i]->in_mob = OUT;
        mob[i]->dir = 1;
        mob[i]->mov = DIR_PLAYER_DOWN;
        mob[i]->draw->id = -88;
    }
    return mob;
}
