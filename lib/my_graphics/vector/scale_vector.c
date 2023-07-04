/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** functions that multiply a factor to each member of the given vector
*/
#include "../include/vector.h"

sfVector2f scale_2vector(sfVector2f vector, float factor)
{
    vector.x *= factor;
    vector.y *= factor;
    return vector;
}

sfVector3f scale_3vector(sfVector3f vector, float factor)
{
    vector.x *= factor;
    vector.y *= factor;
    vector.z *= factor;
    return vector;
}
