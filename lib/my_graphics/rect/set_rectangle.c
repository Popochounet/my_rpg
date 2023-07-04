/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** function that create a rect struct
*/
#include "../include/rect.h"

sfIntRect set_rectangle(int left, int top, int width, int height)
{
    sfIntRect rectangle;
    rectangle.left = left;
    rectangle.top = top;
    rectangle.width = width;
    rectangle.height = height;
    return rectangle;
}
