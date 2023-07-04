/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a layer struct from parameters
*/
#include "../include/layer.h"

// size : size of the texture
// previous : pointer to the lower layer
//            give NULL if there no
// the layer is created with no color and without background
// show variable of new-created layer is set to true
layer_t * create_layer(sfVector2f size, void * previous)
{
    layer_t * layer = malloc(sizeof(layer_t));
    sfColor blank = {0.0, 0.0, 0.0, 0.0};
    sfImage * image = sfImage_createFromColor(size.x, size.y, blank);
    sfTexture * texture = sfTexture_createFromImage(image, NULL);
    layer->type = RDML;
    layer->size = size;
    layer->sprite = sfSprite_create();
    sfSprite_setTexture(layer->sprite, texture, sfTrue);
    layer->texture = sfRenderTexture_create(size.x, size.y, sfTrue);
    sfRenderTexture_drawSprite(layer->texture, layer->sprite, NULL);
    sfRenderTexture_display(layer->texture);
    sfTexture_destroy(texture);
    sfImage_destroy(image);
    layer->draw = NULL;
    layer->show = true;
    layer->next = NULL;
    layer->previous = previous;
    return layer;
}
