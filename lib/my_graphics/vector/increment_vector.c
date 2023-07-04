/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** functions that add a term to each member of the given vector
*/
#include "../include/vector.h"

sfVector2f increment_2vector(sfVector2f vector, float term)
{
    vector.x += term;
    vector.y += term;
    return vector;
}

sfVector3f increment_3vector(sfVector3f vector, float term)
{
    vector.x += term;
    vector.y += term;
    vector.z += term;
    return vector;
}
