/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** functions that swap layers
*/
#include "../include/layer.h"

// the given layer is uppered
// give B
// A->B->C->D
// A->C->B->D
void swap_layer_up(layer_t * layer)
{
    layer_t * B = layer;
    if (B == NULL) {
        return;
    }
    layer_t * A = B->previous;
    layer_t * C = B->next;
    if (C == NULL) {
        return;
    }
    layer_t * D = C->next;
    C->next = B; C->previous = A;
    B->next = D; B->previous = C;
    if (A != NULL) {
        A->next = C;
    }
    if (D != NULL) {
        D->previous = B;
    }
}

// the given layer is lowered
// give C
// A->B->C->D
// A->C->B->D
void swap_layer_down(layer_t * layer)
{
    layer_t * C = layer;
    if (C == NULL) {
        return;
    }
    layer_t * B = C->previous;
    layer_t * D = C->next;
    if (B == NULL) {
        return;
    }
    layer_t * A = B->previous;
    C->next = B; C->previous = A;
    B->next = D; B->previous = C;
    if (A != NULL) {
        A->next = C;
    }
    if (D != NULL) {
        D->previous = B;
    }
}
