/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that initialize a data struct
*/
#include "../include/data.h"

data_t * init_data(void)
{
    data_t * data = malloc(sizeof(data_t));
    data->position = set_3vector(0.f, 0.f, 0.f);
    data->size = set_2vector(0.f, 0.f);
    data->angle = 0.f;
    data->depth = 0.L;
    return data;
}
