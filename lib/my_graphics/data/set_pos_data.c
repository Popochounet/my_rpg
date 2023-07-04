/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function change the position and actualize the depth
*/
#include "../include/data.h"

void set_pos_data(data_t * data, sfVector3f position)
{
    data->position = position;
    data->depth = set_depth(position);
}
