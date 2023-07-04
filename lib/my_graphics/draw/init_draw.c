/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a draw struct
*/
#include "../include/draw.h"

draw_t * init_draw(void)
{
    draw_t * draw = malloc(sizeof(draw_t));
    draw->drawable = NULL;
    draw->type = NO_TYPE;
    draw->show = true;
    draw->data = init_data();
    draw->hitbox = NULL_RECT;
    draw->next = NULL;
    draw->previous = NULL;
    return draw;
}
