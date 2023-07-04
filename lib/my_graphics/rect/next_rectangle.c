/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that move given rect from its width
*/
#include "../include/rect.h"

sfIntRect next_rectangle(sfIntRect rectangle)
{
    rectangle.left += rectangle.width;
    return rectangle;
}
