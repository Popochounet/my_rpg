/*
** EPITECH PROJECT, 2022
** My_rpg_tmp
** File description:
** progress_bar.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

void init_progress_bar
(window_t *wd, progress_bar_t *bar, data_t *data, shape_t *shape)
{
    *bar = (progress_bar_t) {
        .fill = create_draw(shape, SHAPE, data)
    };
}
