/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nils.perriolat
** File description:
** update_sheet.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

const sfIntRect COP_SPRITESHEET_RECTS[DIR_COP_MAX] = {
    [DIR_COP_N] = {192, 0, 64, 72},
    [DIR_COP_NE] = {192 * 5, 0, 64, 72},
    [DIR_COP_E] = {384, 0, 64, 72},
    [DIR_COP_SE] = {192 * 7, 0, 64, 72},
    [DIR_COP_S] = {0, 0, 64, 72},
    [DIR_COP_SW] = {192 * 6, 0, 64, 72},
    [DIR_COP_W] = {576, 0, 64, 72},
    [DIR_COP_NW] = {192 * 4, 0, 64, 72}
};

const sfIntRect BOSS_SPRITESHEET_RECTS[DIR_COP_MAX] = {
    [DIR_COP_N] = {192 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_NE] = {192 * 5 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_E] = {384 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_SE] = {192 * 7 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_S] = {0, 0, 64 * 2, 72 * 2},
    [DIR_COP_SW] = {192 * 6 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_W] = {576 * 2, 0, 64 * 2, 72 * 2},
    [DIR_COP_NW] = {192 * 4 * 2, 0, 64 * 2, 72 * 2}
};

static bool test_dir(draw_t *draw, sfVector2f move, dir_cop_e dir)
{
    const bool conditions[DIR_COP_MAX] = {
        [DIR_COP_N] = move.y < 0 && move.x == 0,
        [DIR_COP_NE] = move.x >= 0 && move.y <= 0,
        [DIR_COP_E] = move.x < 0 && move.y == 0,
        [DIR_COP_S] = move.y >= 0 && move.x == 0,
        [DIR_COP_SE] = move.x >= 0 && move.y >= 0,
        [DIR_COP_SW] = move.x < 0 && move.y >= 0,
        [DIR_COP_W] = move.x >= 0 && move.y == 0,
        [DIR_COP_NW] = move.x < 0 && move.y <= 0
    };

    return conditions[dir];
}

void get_sprt_cop(draw_t *draw, sfVector2f move, dir_cop_e *dir)
{
    if (move.x == 0 && move.y == 0) {
        set_anim_rect_draw(draw, COP_SPRITESHEET_RECTS[DIR_COP_DEFAULT]);
        return;
    }
    for (dir_cop_e i_dir = 0; i_dir < DIR_COP_MAX; i_dir += 2) {
        if (*dir != i_dir && test_dir(draw, move, i_dir)) {
            set_anim_rect_draw(draw, COP_SPRITESHEET_RECTS[i_dir]);
            break;
        }
    }
    for (dir_cop_e i_dir = 1; i_dir < DIR_COP_MAX; i_dir += 2) {
        if (*dir != i_dir && test_dir(draw, move, i_dir)) {
            set_anim_rect_draw(draw, COP_SPRITESHEET_RECTS[i_dir]);
            break;
        }
    }
}

void get_sprt_boss(draw_t *draw, sfVector2f move, dir_cop_e *dir)
{
    if (move.x == 0 && move.y == 0) {
        set_anim_rect_draw(draw, BOSS_SPRITESHEET_RECTS[DIR_COP_DEFAULT]);
        return;
    }
    for (dir_cop_e i_dir = 0; i_dir < DIR_COP_MAX; i_dir += 2) {
        if (*dir != i_dir && test_dir(draw, move, i_dir)) {
            set_anim_rect_draw(draw, BOSS_SPRITESHEET_RECTS[i_dir]);
            break;
        }
    }
    for (dir_cop_e i_dir = 1; i_dir < DIR_COP_MAX; i_dir += 2) {
        if (*dir != i_dir && test_dir(draw, move, i_dir)) {
            set_anim_rect_draw(draw, BOSS_SPRITESHEET_RECTS[i_dir]);
            break;
        }
    }
}
