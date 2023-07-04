/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for text folder
*/
#ifndef MY_GRAPHICS_TEXT
    #define MY_GRAPHICS_TEXT
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "data.h"
    /*
    ** =============================== TEXT ================================
    ** text : pointer to the SFML structure for text.
    ** string : message to display
    ** font : pointer to the SFML structure for font
    **        if NULL, the default font is Arial
    ** color_in : inner color of each character
    ** color_out : outline color of each character
    ** thick : outline thickness of each character
    */
    typedef struct text {
        sfText * text;
        const char * string;
        sfFont * font;
        sfColor color_in;
        sfColor color_out;
        int thick;
    } text_t;

    text_t * init_text(void);
    text_t * create_text(const char * string, sfFont * font, sfColor color);
    void set_pos_text(text_t * text, sfVector3f position);
    void set_size_text(text_t * text, sfVector2f size);
    void set_angle_text(text_t * text, float angle);
    void set_data_text(text_t * text, data_t * data);
    void set_color_in_text(text_t * text, sfColor color);
    void set_color_out_text(text_t * text, sfColor color);
    void set_thick_text(text_t * text, int thick);
    void set_attributes_text(text_t * text, sfColor color_in,
                                sfColor color_out, int thick);
    void set_origin_text(text_t * text, sfVector2f origin);
    sfVector2f get_position_text(text_t * text);
    float get_rotation_text(text_t * text);
    sfVector2f get_scale_text(text_t * text);
    sfVector2f get_origin_text(text_t * text);
    const char * get_string_text(text_t * text);
    void move_text(text_t * text, sfVector2f offset);
    void scale_text(text_t * text, sfVector2f scale);
    void rotate_text(text_t * text, float angle);
    void modify_text(text_t * text, sfVector2f offset,
                    sfVector2f scale, float angle);
    void set_font_text(text_t * text, sfFont * font);
    void set_string_text(text_t * text, const char * string);
    void draw_text(sfRenderTexture * texture, text_t * text);
    void free_text(text_t * text);
#endif
