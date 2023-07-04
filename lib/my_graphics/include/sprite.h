/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for sprite folder
*/
#ifndef MY_GRAPHICS_SPRITE
    #define MY_GRAPHICS_SPRITE
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "vector.h"
    #include "rect.h"
    #include "data.h"
    /*
    ** ============================== SPRITES ==============================
    ** sprite : SFML struct corresponding to a sprite
    ** texture : texture linked to the sprite
    ** rect : area of the texture applied to the sprite
    ** animated : boolean that indicate id the sprite is animated
    ** nb_frame : for animated sprite indicate the number of frames
    **            in the animation
    ** current : for animated sprite indicate the current frame
    */
    typedef struct sprite {
        sfSprite * sprite;
        sfTexture * texture;
        sfIntRect idle_rect;
        bool animated;
        bool loop;
        sfIntRect anim_rect;
        int nb_frame;
        int current;
    } sprite_t;

    sprite_t * init_sprite(void);
    sprite_t * create_sprite(sfTexture * texture, sfIntRect rect);
    void set_pos_sprite(sprite_t * sprite, sfVector3f position);
    void set_angle_sprite(sprite_t * sprite, float angle);
    void set_data_sprite(sprite_t * sprite, data_t * data);
    void set_idle_rect_sprite(sprite_t * sprite, sfIntRect rect);
    void set_texture_sprite(sprite_t * sprite,
                            sfTexture * texture, sfIntRect rect);
    void set_anim_rect_sprite(sprite_t * sprite, sfIntRect rect);
    void switch_animation_sprite(sprite_t * sprite);
    void switch_loop_sprite(sprite_t * sprite);
    void animation_off_sprite(sprite_t * sprite);
    void set_animation_sprite(sprite_t * sprite, sfIntRect rect,
                                int nb_frame, bool loop);
    void set_origin_sprite(sprite_t * sprite, sfVector2f origin);
    sfVector2f get_position_sprite(sprite_t * sprite);
    float get_rotation_sprite(sprite_t * sprite);
    sfVector2f get_scale_sprite(sprite_t * sprite);
    sfVector2f get_origin_sprite(sprite_t * sprite);
    void move_sprite(sprite_t * sprite, sfVector2f offset);
    void scale_sprite(sprite_t * sprite, sfVector2f scale);
    void rotate_sprite(sprite_t * sprite, float angle);
    void modify_sprite(sprite_t * sprite, sfVector2f offset,
                    sfVector2f scale, float angle);
    void draw_sprite(sfRenderTexture * texture, sprite_t * sprite);
    void free_sprite(sprite_t * sprite);
#endif
