/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a window struct from parameters
*/
#include "../include/window.h"

// function that set up the sfRenderWindow struct
// if file is NULL, no icon is set
static sfRenderWindow * setup_window(const char * title,
                        const sfVideoMode mode, const char * file)
{
    sfRenderWindow * win = sfRenderWindow_create(mode, title, sfClose, NULL);
    if (file != NULL) {
        sfImage * icon = sfImage_createFromFile(file);
        sfRenderWindow_setIcon(win, sfImage_getSize(icon).x,
                        sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
        sfImage_destroy(icon);
    }
    sfRenderWindow_setFramerateLimit(win, 120);
    return win;
}

// function that set up the sfView struct
static sfView * setup_view(sfVector2f size)
{
    sfFloatRect rectangle;
    rectangle.top = 0.f;
    rectangle.left = 0.f;
    rectangle.width = size.x;
    rectangle.height = size.y;
    sfView * view = sfView_createFromRect(rectangle);
    return view;
}

// title : title of the sfRenderWindow
// mode : struct that containe the size of the window and the pixel depth
// file : path to an image that can be used as icon for the window
//        if NULL no icon is set
window_t * create_window(const char * title, const sfVideoMode mode,
                        const char * file)
{
    window_t * window = malloc(sizeof(window_t));
    window->size = set_2vector(mode.width, mode.height);
    window->window = setup_window(title, mode, file);
    window->view = setup_view(window->size);
    init_splash_screen(window);
    create_background(window);
    window->core->next = create_layer(window->size, window->core);
    window->fx = window->core->next;
    window->fx->type = FX;
    window->fx->next = create_layer(window->size, window->fx);
    window->ui = window->fx->next;
    window->ui->type = UI;
    window->ui->next = window->splash;
    window->splash->previous = window->ui;
    window->splash->type = SPLASH;
    window->fullscreen = false;
    return window;
}
