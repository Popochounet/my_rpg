/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a list of layers to window
*/
#include "../include/layer.h"

void draw_layers(sfRenderWindow * window, layer_t * layer)
{
    layer_t * current = layer;
    while (current != NULL) {
        draw_single_layer(window, current);
        current = current->next;
    }
}
