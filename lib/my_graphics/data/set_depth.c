/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function calculate the depth from the position
*/
#include "../include/data.h"

long double set_depth(sfVector3f position)
{
    long double depth = 0.L;
    depth += position.z * 10000 + position.y + position.x / 10000;
    return depth;
}
