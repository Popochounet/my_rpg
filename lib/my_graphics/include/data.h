/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for data folder
*/
#ifndef MY_GRAPHICS_DATA
    #define MY_GRAPHICS_DATA
    #include <SFML/System.h>
    #include <stdlib.h>
    #include "vector.h"
    /*
    ** =============================== DATA ================================
    ** position : x y z coordonnees
    ** size : x member is width and y mamber is height
    ** angle : rotation from the initiale position
    ** depth : give the depth position between draws
    */
    typedef struct data {
        sfVector3f position;
        sfVector2f size;
        float angle;
        long double depth;
    } data_t;

    data_t * init_data(void);
    data_t * create_data(sfVector3f position, sfVector2f size, float angle);
    long double set_depth(sfVector3f position);
    void set_pos_data(data_t * data, sfVector3f position);
    void set_size_data(data_t * data, sfVector2f size);
    void set_angle_data(data_t * data, float angle);
    void set_data(data_t * data, sfVector3f position,
                    sfVector2f size, float angle);
#endif
