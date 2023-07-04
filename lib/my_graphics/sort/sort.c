/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** function that sort a list of draw by depth
*/

#include "../include/sort.h"

static draw_t * sub_algo(draw_t * current, draw_t * first, int * nb_swap)
{
    while (current != NULL) {
        if (current->next == NULL) {
            current = current->next; continue;
        } long double current_d = set_depth(current->data->position);
        draw_t * next = current->next;
        long double next_d = set_depth(next->data->position);
        if (next_d < current_d) {
            swap_draw_next(current); *nb_swap += 1;
            first = (current == first) ? next : first;
            continue;
        } current = next;
    }
    return first;
}

static draw_t * algo(draw_t * list)
{
    int nb_swap = 1;
    draw_t * first = list;
    while (nb_swap > 0) {
        draw_t * current = first;
        nb_swap = 0;
        first = sub_algo(current, first, &nb_swap);
    } return first;
}

draw_t * sort_draws(draw_t * draw)
{
    if (draw == NULL)
        return NULL;
    draw = algo(draw);
    return draw;
}
