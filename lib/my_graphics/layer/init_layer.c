/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a layer struct
*/
#include "../include/layer.h"

layer_t * init_layer(void)
{
    layer_t * layer = malloc(sizeof(layer_t));
    layer->type = RDML;
    layer->size = set_2vector(0.f, 0.f);
    layer->texture = NULL;
    layer->sprite = NULL;
    layer->draw = NULL;
    layer->show = true;
    layer->next = NULL;
    layer->previous = NULL;
    return layer;
}
