/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a data struct from parameters
*/
#include "../include/data.h"

data_t * create_data(sfVector3f position, sfVector2f size, float angle)
{
    data_t * data = malloc(sizeof(data_t));
    data->position = position;
    data->size = size;
    data->angle = angle;
    data->depth = set_depth(position);
    return data;
}
