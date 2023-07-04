/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that draw a list of draws to layer
*/
#include "../include/draw.h"
#include <stdio.h>

void draw_draws(sfRenderTexture * texture, draw_t * draw)
{
    draw_t * current = draw;
    while (current != NULL) {
        draw_single_draw(texture, current);
        current = current->next;
    }
}

/*
DEPRECATED:

static void simple_draw_draws(sfRenderTexture * texture, draw_t * draw)
{
    draw_t * current = draw;
    while (current != NULL) {
        draw_single_draw(texture, current);
        current = current->next;
    }
}

static bool in_view(draw_t * draw, sfVector2f min, sfVector2f max)
{
    sfVector2f pos = set_2vector(draw->data->position.x,
                                draw->data->position.y);
    min.x -= draw->data->size.x;
    min.y -= draw->data->size.y;
    max.x += draw->data->size.x;
    max.y += draw->data->size.y;
    if (min.x <= pos.x && pos.x <= max.x && min.y <= pos.y && pos.y <= max.x) {
        return true;
    }
    return false;
}

void draw_draws(sfRenderTexture * texture, draw_t * draw, sfView * view)
{
    if (view == NULL) {
        simple_draw_draws(texture, draw); return;
    }
    sfVector2f center = sfView_getCenter(view);
    sfVector2f sz = sfView_getSize(view);
    sfVector2f min = set_2vector(center.x - (sz.x / 2), center.y - (sz.y / 2));
    sfVector2f max = set_2vector(center.x + (sz.x / 2), center.y + (sz.y / 2));
    draw_t * current = draw;
    while (current != NULL) {
        if (in_view(draw, min, max)) {
            draw_single_draw(texture, current);
        }
        current = current->next;
    }
}
*/
