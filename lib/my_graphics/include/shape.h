/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for shape folder
*/
#ifndef MY_GRAPHICS_SHAPE
    #define MY_GRAPHICS_SHAPE
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "data.h"
    /*
    ** ============================== SHAPES ===============================
    ** type : specify if the shape is a square or a circle
    ** shape : pointer to the sfml square or shape struct
    ** color_in : define the color that fill the inner space of the shape
    ** color_out : define the color that fill the outline of the shape
    ** thick : thickness of the outline of the shape
    */
    typedef enum shape_type {
        NO_SHAPE,
        CIRCLE,
        RECT
    } shape_type_t;

    typedef struct shape {
        shape_type_t type;
        void * shape;
        sfColor color_in;
        sfColor color_out;
        int thick;
    } shape_t;

    shape_t * init_shape(void);
    shape_t * create_shape(shape_type_t type, sfColor color_in,
                            sfColor color_out, int thick);
    void set_pos_shape(shape_t * shape, sfVector3f position);
    void set_size_shape(shape_t * shape, sfVector2f size);
    void set_angle_shape(shape_t * shape, float angle);
    void set_data_shape(shape_t * shape, data_t * data);
    void set_shape_shape(shape_t * shape, shape_type_t type);
    void set_color_in_shape(shape_t * shape, sfColor color);
    void set_color_out_shape(shape_t * shape, sfColor color);
    void set_thick_shape(shape_t * shape, int thick);
    void set_attributes_shape(shape_t * shape, sfColor color_in,
                            sfColor color_out, int thick);

    void set_origin_shape(shape_t * shape, sfVector2f origin);
    sfVector2f get_position_shape(shape_t * shape);
    float get_rotation_shape(shape_t * shape);
    sfVector2f get_scale_shape(shape_t * shape);
    sfVector2f get_origin_shape(shape_t * shape);
    void move_shape(shape_t * shape, sfVector2f offset);
    void scale_shape(shape_t * shape, sfVector2f scale);
    void rotate_shape(shape_t * shape, float angle);
    void modify_shape(shape_t * shape, sfVector2f offset,
                    sfVector2f scale, float angle);

    void draw_shape(sfRenderTexture * texture, shape_t * shape);
    void free_shape(shape_t * shape);
#endif
