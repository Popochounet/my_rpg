/*
** EPITECH PROJECT, 2022
** library MY_GRAPHICS
** File description:
** functions that handle splash screen
*/
#include "../include/window.h"

// function that initialize the splash screen when the window is created
void init_splash_screen(window_t* wd)
{
    wd->splash = create_layer(wd->size, NULL); sfVector3f null_pos =
    set_3vector(0, 0, 0); sfVector3f pos_bar = set_3vector(10, 900, 0);
    sfVector2f wind = set_2vector(1920, 1080);
    sprite_t * sprite = init_sprite();
    data_t * data1 = create_data(null_pos, wind, 0.f);
    sfIntRect rect = set_rectangle(0, 0, 2736, 2310);
    sfTexture * image = sfTexture_createFromFile("./images/splash.png", NULL);
    set_texture_sprite(sprite, image, rect); set_data_sprite(sprite, data1);
    draw_t * draw1 = create_draw(sprite, SPRITE, data1);
    wd->splash->draw = draw1;
    data_t * data2 = create_data(pos_bar, set_2vector(1900, 50), 0.f);
    shape_t * shape2 = create_shape(RECT, sfBlack, sfBlack, 1);
    set_data_shape(shape2, data2);
    draw_t * draw2 = create_draw(shape2, SHAPE, data2);
    wd->splash->draw->next = draw2; draw2->previous = draw1;
    data_t * data3 = create_data(pos_bar, set_2vector(0, 50), 0.f);
    shape_t * shape3 = create_shape(RECT, sfGreen, sfGreen, 0);
    set_data_shape(shape3, data3);
    draw_t * draw3 = create_draw(shape3, SHAPE, data3);
    wd->splash->draw->next->next = draw3; draw3->previous = draw2;
}

// function that animate the splash screen, main = 1: normal; main = 0: revert
void move_splash(window_t* wd, int main)
{
    if (main) {
        wd->splash->draw->data->position.x -= 0.40;
        wd->splash->draw->data->position.y -= 0.3377193;
        if (wd->splash->draw->data->position.x < -684) {
            wd->splash->draw->data->position.x = 0;
            wd->splash->draw->data->position.y = 0;
        }
    } else {
        wd->splash->draw->data->position.x += 0.40 * 4;
        wd->splash->draw->data->position.y += 0.3377193 * 4;
        if (wd->splash->draw->data->position.x >= 0) {
            wd->splash->draw->data->position.x = -684;
            wd->splash->draw->data->position.y = -577.5;
        }
    }
}

// function that animate and display a layer splash during window creation
void splash_screen(window_t * wd, int x, int x_max)
{
    move_splash(wd, 1);
    wd->splash->draw->next->next->data->size.x =
                            (float)x / (float)(x_max) * 1900;
    sfRenderTexture_setView(wd->splash->texture, wd->view);
    draw_single_layer(wd->window, wd->splash);
    sfRenderWindow_display(wd->window);
}
