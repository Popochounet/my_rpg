/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that add a layer to a layer section (see layer_type enum)
** the given layer will be put in the last position of the section
*/
#include "../include/window.h"

// first : correspond to the first layer of a section
//         to avoid error, use only the layers referenced in your window
// layer : layer you want to add
void append_layer(layer_t * first, layer_t * layer)
{
    layer_type_t type = first->type;
    while (first->next != NULL && (first->next->type == type + 1)) {
        first = first->next;
    }
    layer_t * next = first->next;
    first->next = layer;
    layer->previous = first;
    if (next != NULL) {
        layer->next = next;
        next->previous = layer;
    }
}
