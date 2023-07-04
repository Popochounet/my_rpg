/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the data struct linked to a draw
*/
#include "../include/draw.h"

// set the position of a draw
void set_pos_draw(draw_t * draw, sfVector3f position)
{
    draw->data->position = position;
    draw->hitbox.left = position.x;
    draw->hitbox.top = position.y;
    switch (draw->type) {
        case SHAPE:
            set_pos_shape((shape_t *)(draw->drawable), position);
        break;
        case SPRITE:
            set_pos_sprite((sprite_t *)(draw->drawable), position);
        break;
        case TEXT:
            set_pos_text((text_t *)(draw->drawable), position);
        break;
        default: break;
    }
}

// set the size of a draw
void set_size_draw(draw_t * draw, sfVector2f size)
{
    draw->data->size = size;
    switch (draw->type) {
        case SHAPE:
            set_size_shape((shape_t *)(draw->drawable), size);
        break;
        case TEXT:
            set_size_text((text_t *)(draw->drawable), size);
        break;
        default: break;
    }
}

// set the rotation of a draw
void set_angle_draw(draw_t * draw, float angle)
{
    draw->data->angle = angle;
    switch (draw->type) {
        case SHAPE:
            set_angle_shape((shape_t *)(draw->drawable), angle);
        break;
        case SPRITE:
            set_angle_sprite((sprite_t *)(draw->drawable), angle);
        break;
        case TEXT:
            set_angle_text((text_t *)(draw->drawable), angle);
        break;
        default: break;
    }
}

// set the position, the size and the rotation of a draw
void set_data_draw(draw_t * draw, data_t * data)
{
    draw->data = data;
    switch (draw->type) {
        case SHAPE:
            set_data_shape((shape_t *)(draw->drawable), draw->data);
        break;
        case SPRITE:
            set_data_sprite((sprite_t *)(draw->drawable), draw->data);
        break;
        case TEXT:
            set_data_text((text_t *)(draw->drawable), draw->data);
        break;
        default: break;
    }
}
