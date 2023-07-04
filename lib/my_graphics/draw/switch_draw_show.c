/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that invert the value of the show variable of a draw
*/
#include "../include/draw.h"

void switch_draw_show(draw_t * draw)
{
    if (draw->show) {
        draw->show = false;
    } else {
        draw->show = true;
    }
}
