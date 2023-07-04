/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** header for sort folder
*/

#ifndef MY_GRAPHICS_SORT
    #define MY_GRAPHICS_SORT
    #include <stdlib.h>
    #include "draw.h"

    draw_t *partition(draw_t *l_a, draw_t *pivot);

    void swap(draw_t **list);
    void swap_all(draw_t **l_a, draw_t **l_b);
    void push(draw_t **dest, draw_t **src);
    void rotate(draw_t **list);
    void rotate_all(draw_t **l_a, draw_t **l_b);
    void rotate_right(draw_t **list);
    void rotate_right_all(draw_t **l_a, draw_t **l_b);

    draw_t * sort_draws(draw_t * draw);
#endif
