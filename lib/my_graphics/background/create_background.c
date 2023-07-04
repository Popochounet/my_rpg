/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that parse a tmx file into a sprite list
*/
#include "../include/background.h"
#include "../include/window.h"
#include "../../../include/my_macros.h"
#include <stdio.h>
#include <stdlib.h>

static char * get_path(int id, tmx_t * tmx)
{
    while (tmx != NULL) {
        if (tmx->id == id) {
            char * str = malloc(mystrlen("images/map/") +
                                mystrlen(tmx->path) + 1);
            mystrcpy(str, "images/map/");
            mystrcat(str, tmx->path);
            return str;
        }
        tmx = tmx->next;
    }
    return NULL;
}

void get_position(sfVector2f position, int ** map,
                        tmx_t * tmx, layer_t * layer)
{
    int id = map[(int)position.y][(int)position.x]; RETURN_IF(id == -1);
    while (tmx->id != id) {
        tmx = tmx->next;
    } sfVector3f pos = set_3vector(position.x * 64 + tmx->width / 2,
                                    position.y * 64 - 5, 0.f);
    sfVector2f size = set_2vector(tmx->width, tmx->height);
    char * path = get_path(id, tmx); draw_t * draw = NULL;
    data_t * data = create_data(pos, size, 0.f);
    sprite_t * sprite = init_sprite();
    set_data_sprite(sprite, data);
    sfTexture * texture = sfTexture_createFromFile(path, NULL);
    set_texture_sprite(sprite, texture,
                        set_rectangle(0, 0, tmx->width, tmx->height));
    draw = create_draw(sprite, SPRITE, data);
    change_hitbox(draw, set_rectangle(-(size.x / 2), -(size.y - 5),
    size.x, size.y));
    draw->id = id;
    set_origin_draw(draw, set_2vector(size.x / 2, size.y - 5));
    append_draw_layer(layer, draw);
    free(path);
}

static int initializing_draws(window_t * wd, int *** maps,
                                tmx_t * tmx, needs_t needs)
{
    sfEvent event;
    get_position(needs.pos, maps[0], tmx, wd->background);
    get_position(needs.pos, maps[1], tmx, wd->core);
    while (sfRenderWindow_pollEvent(wd->window, &event)) {
        if (event.type == sfEvtClosed) {
            write(2, "abort background creation\n", 26);
            return 84;
        }
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(needs.clock)) >= 0.01) {
        splash_screen(wd, needs.i, needs.tt);
        sfClock_restart(needs.clock);
    }
    return 0;
}

static void my_while(window_t * wd, int *** maps, tmx_t * tmx, needs_t needs)
{
    int error = 0;
    while (needs.pos.y < needs.height) {
        needs.pos.x = 0;
        while (needs.pos.x < needs.width) {
            error = initializing_draws(wd, maps, tmx, needs);
            needs.pos.x++; needs.i++;
        } needs.pos.y++;
        if (error) { break;
        }
    }
}

void create_background(window_t * wd)
{
    tmx_t * tmx = parser_tmx("images/csv_and_tmx/All_map2.tmx"); needs_t needs;
    int ** background = parser_csv("./images/csv_and_tmx/map2_Background.csv");
    int ** core = parser_csv("./images/csv_and_tmx/map2_Core.csv");
    int *** maps = malloc(sizeof(int **) * 2); maps[0] = background;
    maps[1] = core; needs.width = 0; needs.height = 0;
    if (tmx == NULL || background == NULL || core == NULL) {
        write(2, "abort background creation\n", 26);
    } while (background[0][needs.width] != -2) { needs.width++;
    } while (background[needs.height] != NULL) { needs.height++;
    } wd->map_size = set_2vector(needs.width * 64, needs.height * 64);
    needs.tt = needs.width * needs.height; needs.i = 0;
    needs.pos = set_2vector(0.f, 0.f); needs.clock = sfClock_create();
    wd->background = create_layer(set_2vector(1920, 1080), NULL);
    wd->core = create_layer(set_2vector(1920, 1080), wd->background);
    wd->background->type = BACKGROUND; wd->core->type = CORE;
    wd->background->next = wd->core; my_while(wd, maps, tmx, needs);
    for (int i = 0; background[i] != NULL; i++) {
        free(background[i]); free(core[i]);
    } free(background); free(core); free_tmx(tmx); free(maps);
    sfClock_destroy(needs.clock);
}
