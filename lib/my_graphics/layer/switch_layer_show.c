/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that invert the value of the show variable of a layer
*/
#include "../include/layer.h"

void switch_layer_show(layer_t * layer)
{
    if (layer->show) {
        layer->show = false;
    } else {
        layer->show = true;
    }
}
