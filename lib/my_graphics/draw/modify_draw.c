/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that apply relative modification to the draw
*/
#include "../include/draw.h"

// move the draw of the given offset
void move_draw(draw_t * draw, sfVector2f offset)
{
    if (draw->id >= 0) {
        return;
    }
    draw->data->position.x += offset.x;
    draw->data->position.y += offset.y;
    draw->hitbox.left = draw->data->position.x;
    draw->hitbox.top = draw->data->position.y;
    switch (draw->type) {
        case SHAPE:
            move_shape((shape_t *)(draw->drawable), offset);
        break;
        case SPRITE:
            move_sprite((sprite_t *)(draw->drawable), offset);
        break;
        case TEXT:
            move_text((text_t *)(draw->drawable), offset);
        break;
        default: break;
    }
}

// scale the size of the draw
void scale_draw(draw_t * draw, sfVector2f scale)
{
    if (draw->id >= 0) {
        return;
    }
    draw->data->size.x *= scale.x;
    draw->data->size.y *= scale.y;
    switch (draw->type) {
        case SHAPE:
            scale_shape((shape_t *)(draw->drawable), scale);
        break;
        case SPRITE:
            scale_sprite((sprite_t *)(draw->drawable), scale);
        break;
        case TEXT:
            scale_text((text_t *)(draw->drawable), scale);
        break;
        default: break;
    }
}

// rotate the draw of the given angle
void rotate_draw(draw_t * draw, float angle)
{
    if (draw->id >= 0) {
        return;
    }
    draw->data->angle += angle;
    switch (draw->type) {
        case SHAPE:
            rotate_shape((shape_t *)(draw->drawable), angle);
        break;
        case SPRITE:
            rotate_sprite((sprite_t *)(draw->drawable), angle);
        break;
        case TEXT:
            rotate_text((text_t *)(draw->drawable), angle);
        break;
        default: break;
    }
}

// move, scale and rotate the draw with the parameters
void modify_draw(draw_t * draw, sfVector2f offset,
                    sfVector2f scale, float angle)
{
    if (draw->id >= 0) {
        return;
    } switch (draw->type) {
        case SHAPE:
            modify_shape((shape_t *)(draw->drawable), offset, scale, angle);
        break;
        case SPRITE:
            modify_sprite((sprite_t *)(draw->drawable), offset, scale, angle);
        break;
        case TEXT:
            modify_text((text_t *)(draw->drawable), offset, scale, angle);
        break;
        default: break;
    }
}
