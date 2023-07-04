/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mypaint-adrien.audiard
** File description:
** manage_mouse.c
*/

#include <my_rpg.h>
#include <my_graphics.h>

static void handle_mouse_release
(list_button_t* all_btn, sfMouseButtonEvent *event)
{
    if (all_btn->btn->is_released(all_btn->btn, event)) {
        set_color_in_draw(all_btn->btn->rect, sfWhite);
    }
}

void mouse_button_released(sfRenderWindow* wd, sfMouseButtonEvent evt,
    list_button_t* all_btn)
{
    while (all_btn != NULL) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show)
            handle_mouse_release(all_btn, &evt);
        else {
            all_btn->btn->state = NONE;
        }
        all_btn = all_btn->next;
    }
}

void mouse_button_pressed(window_t* wd, sfMouseButtonEvent evt,
    game_src_t* g_src)
{
    button_pressed(wd, g_src->all_btn, evt, g_src);
}

void button_hovered(list_button_t* all_btn, sfMouseMoveEvent evt)
{
    while (all_btn != NULL) {
        if (all_btn->btn->layer_on->show && all_btn->btn->rect->show &&
            all_btn->btn->is_hover(all_btn->btn, &evt)) {
                set_color_out_draw(all_btn->btn->rect, sfRed);
        } else {
            set_color_out_draw(all_btn->btn->rect, sfBlack);
        }
        all_btn = all_btn->next;
    }
}

void mouse_moved(sfMouseMoveEvent evt, game_src_t* g_src)
{
    button_hovered(g_src->all_btn, evt);
    sliding_button_moved(g_src->all_btn, evt);
}
