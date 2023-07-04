/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that swap draws
*/
#include "../include/draw.h"

// the given draw is uppered
// give B
// A->B->C->D
// A->C->B->D
void swap_draw_next(draw_t * draw)
{
    draw_t * B = draw;
    if (B == NULL) {
        return;
    }
    draw_t * A = B->previous;
    draw_t * C = B->next;
    if (C == NULL) {
        return;
    }
    draw_t * D = C->next;
    C->next = B; C->previous = A;
    B->next = D; B->previous = C;
    if (A != NULL) {
        A->next = C;
    }
    if (D != NULL) {
        D->previous = B;
    }
}

// the given draw is lowered
// give C
// A->B->C->D
// A->C->B->D
void swap_draw_previous(draw_t * draw)
{
    draw_t * C = draw;
    if (C == NULL) {
        return;
    }
    draw_t * B = C->previous;
    draw_t * D = C->next;
    if (B == NULL) {
        return;
    }
    draw_t * A = B->previous;
    C->next = B; C->previous = A;
    B->next = D; B->previous = C;
    if (A != NULL) {
        A->next = C;
    }
    if (D != NULL) {
        D->previous = B;
    }
}
