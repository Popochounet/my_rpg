/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that add a draw struct to a layer
*/
#include "../include/layer.h"

// draw : draw struct you want to add
// layer : layer where you want your draw to be displayed
void append_draw_layer(layer_t * layer, draw_t * draw)
{
    draw_t * current = layer->draw;
    layer->draw = draw;
    if (current != NULL) {
        current->previous = draw;
        draw->next = current;
    }
}
