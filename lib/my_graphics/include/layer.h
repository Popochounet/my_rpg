/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for layer folder
*/
#ifndef MY_GRAPHICS_LAYER
    #define MY_GRAPHICS_LAYER
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "vector.h"
    #include "draw.h"
    #include "sort.h"
    /*
    ** =============================== LAYER ===============================
    ** type : indicate to which section of the window the layer belong
    ** size : vector that give width and height
    ** texture : sfml struct for dynamic texture
    ** sprite : used to draw the texture on the window
    ** draw : chained list of draw struct
    ** show : boolean that says if the layer must be displayed or not
    ** next : pointer to the upper layer
    **        is NULL if there is no next
    ** previous : pointer to the lower layer
    **            is NULL if there is no previous
    */
    typedef enum layer_type {
        RDML,
        BACKGROUND,
        CORE,
        FX,
        UI,
        SPLASH
    } layer_type_t;

    typedef struct layer layer_t;

    struct layer {
        layer_type_t type;
        sfVector2f size;
        sfRenderTexture * texture;
        sfSprite * sprite;
        draw_t * draw;
        bool show;
        layer_t * next;
        layer_t * previous;
    };

    layer_t * init_layer(void);
    layer_t * create_layer(sfVector2f size, void * previous);
    void switch_layer_show(layer_t * layer);
    void swap_layer_up(layer_t * layer);
    void swap_layer_down(layer_t * layer);
    void append_draw_layer(layer_t * layer, draw_t * draw);
    void draw_single_layer(sfRenderWindow * window, layer_t * layer);
    void draw_from_to_layer(sfRenderWindow * window, layer_t * from,
                            layer_t * to);
    void draw_section_layer(sfRenderWindow * window, layer_t * layer);
    void draw_layers(sfRenderWindow * window, layer_t * layer);
    void free_single_layer(layer_t * layer);
    void free_layers(layer_t * layer);
#endif
