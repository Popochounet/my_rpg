/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the draw
*/
#include "../include/draw.h"

bool intersect_with_draw(draw_t * draw1, draw_t * draw2)
{
    sfIntRect rect1 = draw1->hitbox;
    sfIntRect rect2 = draw2->hitbox;
    return sfIntRect_intersects(&rect1, &rect2, NULL);
}

bool intersect_with_id(draw_t * draw1, draw_t * list, int id)
{
    while (list != NULL) {
        bool result = (list->id == id) ? intersect_with_draw(draw1, list) : 0;
        if (result) {
            return true;
        }
        list = list->next;
    }
    return false;
}

bool intersect_with_map(draw_t * draw1, draw_t * list)
{
    while (list != NULL) {
        bool result = (list->id >= 0) ? intersect_with_draw(draw1, list) : 0;
        if (result) {
            return true;
        }
        list = list->next;
    }
    return false;
}

bool intersect_with_all(draw_t * draw1, draw_t * list)
{
    while (list != NULL) {
        bool result = intersect_with_draw(draw1, list);
        if (result) {
            return true;
        }
        list = list->next;
    }
    return false;
}
