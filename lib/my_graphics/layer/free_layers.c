/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a list of layer struct
*/
#include "../include/layer.h"

void free_layers(layer_t * layer)
{
    layer_t * current = layer;
    layer_t * next = NULL;
    while (current != NULL) {
        next = current->next;
        free_single_layer(current);
        current = next;
    }
}
