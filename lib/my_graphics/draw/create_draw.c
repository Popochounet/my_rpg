/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a draw struct from parameters
*/
#include "../include/draw.h"

// drawable : pointer to a drawable sub structure (shape_t, sprite_t or text_t)
// type : the type corresponding to the type of drawable
// data : the data structure that will be linked to this draw
draw_t * create_draw(void * drawable, draw_type_t type, data_t * data)
{
    draw_t * draw = malloc(sizeof(draw_t));
    draw->drawable = drawable;
    draw->type = type;
    draw->id = -1;
    draw->show = true;
    draw->data = data;
    draw->hitbox = set_rectangle(data->position.x, data->position.y,
                                    data->size.x, data->size.y);
    draw->next = NULL;
    draw->previous = NULL;
    return draw;
}
