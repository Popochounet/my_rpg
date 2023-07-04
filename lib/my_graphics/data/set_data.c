/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that change the position, size, angle and actualize depth
*/
#include "../include/data.h"

void set_data(data_t * data, sfVector3f position, sfVector2f size, float angle)
{
    data->position = position;
    data->size = size;
    data->angle = angle;
    data->depth = set_depth(position);
}
