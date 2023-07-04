/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a draw struct from parameters
*/
#include "../include/draw.h"

void remove_single_draw(draw_t * draw)
{
    draw_t * previous = draw->previous;
    draw_t * next = draw->next;
    free_single_draw(draw);
    if (previous != NULL) {
        previous->next = next;
    }
    if (next != NULL) {
        next->previous = previous;
    }
}
