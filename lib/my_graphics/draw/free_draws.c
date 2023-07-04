/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a list of draw struct
*/
#include "../include/draw.h"

void free_draws(draw_t * draw)
{
    draw_t * current = draw;
    draw_t * next = NULL;
    while (current != NULL) {
        next = current->next;
        free_single_draw(current);
        current = next;
    }
}
