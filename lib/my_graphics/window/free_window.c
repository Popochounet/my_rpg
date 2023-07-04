/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that free a window struct
*/
#include "../include/window.h"

// The function will call all functions needed to free all structs in the
// window. So, you should not need to call the free sub-functions.
void free_window(window_t * window)
{
    if (window->window)
        sfRenderWindow_destroy(window->window);
    sfView_destroy(window->view);
    free_layers(window->background);
    free(window);
}
