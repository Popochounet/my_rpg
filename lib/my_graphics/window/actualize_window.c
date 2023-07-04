/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that actualize the displaying of a window
*/
#include "../include/window.h"

// reset screen -> apply view to core -> display core & ui -> actualize window
// if you want to apply those instructions separatly see the draw functions in
// layer/ and in draw/ (or in their header in include/)
void actualize_window(window_t * window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderTexture_setView(window->background->texture, window->view);
    sfRenderTexture_setView(window->core->texture, window->view);
    sfRenderTexture_setView(window->fx->texture, window->view);
    draw_layers(window->window, window->background);
    sfRenderWindow_display(window->window);
}
