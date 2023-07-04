/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for background folder
*/
#ifndef MY_GRAPHICS_BACKGROUND
    #define MY_GRAPHICS_BACKGROUND
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <string.h>
    #include "vector.h"
    #include "layer.h"
    #include "draw.h"
    #include "sprite.h"
    #include "shape.h"
    #include "data.h"
    #include "../background/my.h"
    /*
    ** ============================ BACKGROUND =============================
    ** id :
    ** width :
    ** height :
    ** path :
    ** next :
    ** previous :
    */
    typedef struct window window_t;
    typedef enum tmx_step { NO_STEP, ID, WIDTH, HEIGHT, PATH } tmx_step_t;
    typedef struct tmx tmx_t;

    struct tmx {
        int id;
        int width;
        int height;
        char * path;
        tmx_t * next;
        tmx_t * previous;
    };

    typedef struct needs {
        sfVector2f pos;
        sfClock * clock;
        int i;
        int tt;
        int width;
        int height;
    } needs_t;

    tmx_t * create_tmx(tmx_t * previous);
    tmx_t * parser_tmx(char const * path);
    int ** parser_csv(char const * path);
    void create_background(window_t * wd);
    void free_tmx(tmx_t * tmx);
#endif
