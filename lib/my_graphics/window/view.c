/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function to manipulate sfView in window struct
*/
#include "../include/window.h"

// set the new size of the view to the given size
void view_resize(window_t * window, sfVector2f size)
{
    sfView_setSize(window->view, size);
}

// set the center of the camera to the given position
void view_center(window_t * window, sfVector2f position)
{
    sfView_setCenter(window->view, position);
}

// set the new rotation of the camera to the given angle
void view_set_rotation(window_t * window, float angle)
{
    sfView_setRotation(window->view, angle);
}

// add the given angle to the actual rotation of the camera
void view_rotate(window_t * window, float angle)
{
    sfView_rotate(window->view, angle);
}

// resize the view simulating a zoom of the given factor
void view_zoom(window_t * window, float factor)
{
    sfView_zoom(window->view, factor);
}
