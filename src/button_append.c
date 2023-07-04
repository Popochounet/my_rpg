/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** button_append.c
*/

#include <my_graphics.h>
#include <my_rpg.h>

button_s_t* append_button_layer(layer_t* layer, button_s_t* btn)
{
    append_draw_layer(layer, btn->name);
    append_draw_layer(layer, btn->rect);
    btn->layer_on = layer;
    return btn;
}

sliding_button_t** append_s_button_layer(layer_t* layer,
    sliding_button_t** s_btn, int nb_s_btn)
{
    for (int i = 0; i < nb_s_btn; i++) {
        s_btn[i]->btn = append_button_layer(layer, s_btn[i]->btn);
        append_draw_layer(layer, s_btn[i]->line);
    }
    return s_btn;
}

list_button_t* append_btn_list(list_button_t* list, button_s_t* btn)
{
    list_button_t* new_btn = malloc(sizeof(list_button_t));
    new_btn->btn = btn;
    new_btn->next = list;
    return new_btn;
}
