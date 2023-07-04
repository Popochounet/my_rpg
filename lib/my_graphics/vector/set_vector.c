/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** functions that create a vector
*/
#include "../include/vector.h"

sfVector2f set_2vector(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

sfVector3f set_3vector(float x, float y, float z)
{
    sfVector3f vector;
    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}
