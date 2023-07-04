/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw layers that are between two given (the two are included)
*/
#include "../include/layer.h"

void draw_section_layer(sfRenderWindow * window, layer_t * layer)
{
    layer_t * current = layer;
    layer_type_t type = current->type;
    while (current != NULL) {
        if (current->type != type) {
            return;
        }
        draw_single_layer(window, current);
        current = current->next;
    }
}
