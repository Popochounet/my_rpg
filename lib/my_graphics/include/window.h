/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for window folder
*/
#ifndef MY_GRAPHICS_WINDOW
    #define MY_GRAPHICS_WINDOW
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "vector.h"
    #include "layer.h"
    #include "background.h"
    /*
    ** ============================== WINDOW ===============================
    ** size : vector that give width and height
    ** window : sfml dynamic window
    ** view : sfml camera to crop core layer if needed
    ** background : layer that display the background of the app
    **              that layer is created with the window
    ** core : layer that display the core of the app
    **        all pre-defined elements with hitbox are created in this layer
    **        when the window is created
    **        you should add your usable elements in this layer
    ** fx : layer created to manipulate only your fx
    ** ui : layer that display the user interface
    ** splash : layer that contain the splash screen
    */
    typedef struct window {
        sfVector2f size;
        sfVector2f map_size;
        sfRenderWindow * window;
        sfView * view;
        bool fullscreen;
        layer_t * background;
        layer_t * core;
        layer_t * fx;
        layer_t * ui;
        layer_t * splash;
    } window_t;

    window_t * init_window(void);
    window_t * create_window(const char * title, const sfVideoMode mode,
                            const char * file);
    void actualize_window(window_t * window);
    void window_windowed(window_t * window, const char * title,
                        const sfVideoMode mode, const char * file);
    void window_fullscreen(window_t * window, const char * title,
                        const sfVideoMode mode, const char * file);
    void append_layer(layer_t * first, layer_t * layer);
    void view_resize(window_t * window, sfVector2f size);
    void view_center(window_t * window, sfVector2f center);
    void view_set_rotation(window_t * window, float angle);
    void view_rotate(window_t * window, float angle);
    void view_zoom(window_t * window, float factor);
    void free_window(window_t * window);

    /*
    ** ============================== SPLASH ===============================
    */
    void init_splash_screen(window_t* wd);
    void splash_screen(window_t * wd, int x, int x_max);
    void move_splash(window_t* wd, int main);

#endif
