/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** core.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

void my_function0(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function1(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function2(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function3(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function4(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function5(game_src_t* g_src, float * move, int * step, void ** var);
void my_function6(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);
void my_function7(game_src_t* g_src, sfClock * clock, int * step, mob_t * ami);

static mob_t * init_single_mob(window_t* wd)
{
    mob_t * mob = malloc(sizeof(mob_t));
    sprite_t *sprite = init_sprite();
    sfTexture *texture = sfTexture_createFromFile
    ("images/spritesheets/casseur_spritesheet.png", NULL);
    sfVector2f pos = set_2vector(380, 600);
    data_t *data = create_data(set_3vector(pos.x, pos.y, 0),
    set_2vector(48, 72), 0.f);
    set_texture_sprite(sprite, texture, (sfIntRect) {0, 0, 48, 72});
    mob->draw = create_draw(sprite, SPRITE, data);
    set_origin_draw(mob->draw, set_2vector
        (data->size.x / 2, data->size.y - 5));
    set_origin_draw(mob->draw, (sfVector2f) {48 / 2, 72 / 2});
    set_animation_draw(mob->draw, (sfIntRect) {0, 0, 48, 72}, 11, true);
    append_draw_layer(wd->core, mob->draw);
    mob->in_mob = OUT;
    mob->dir = 1;
    mob->mov = DIR_PLAYER_DOWN;
    mob->draw->id = -88;
    return mob;
}

void tuto(window_t* wd, game_src_t* g_src)
{
    sfClock * clock = sfClock_create(); float time = 0.f; int step = 0;
    set_pos_draw(g_src->game->crowd->player->draw, set_3vector(1400, 600, 0));
    mob_t * ami = init_single_mob(wd); sfVector3f pos = set_3vector(0, 0, 0);
    sfVector3f position = g_src->game->crowd->player->draw->data->position;
    set_pos_draw(ami->draw, set_3vector(position.x + 30, position.y - 40, 0));
    float move = 0.f; void * var[2] = {(void *)ami, (void *)wd}; while (step <
    9 && sfRenderWindow_isOpen(wd->window) && !g_src->menu->show) {
    time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    pos = g_src->game->crowd->player->draw->data->position; switch (step) {
    case 0: my_function0(g_src, clock, &step, ami); break; case 1:
    my_function1(g_src, clock, &step, ami); break; case 2: my_function2(g_src,
    clock, &step, ami); break; case 3: my_function3(g_src, clock, &step, ami);
    break; case 4: my_function4(g_src, clock, &step, ami); break; case 5:
    my_function5(g_src, &move, &step, var); break; case 6: my_function6(g_src,
    clock, &step, ami); break; case 7: my_function7(g_src, clock, &step, ami);
    break; case 8: if (time > 1.5) {speech_bubble_clean(g_src->game); step++;
            } break; default: break;
        } view_center(wd, set_2vector(pos.x, pos.y)); actualize_window(wd);
    } remove_single_draw(ami->draw); sfClock_destroy(clock);
    g_src->tuto = false;
}
