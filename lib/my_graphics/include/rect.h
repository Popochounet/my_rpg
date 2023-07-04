/*
** EPITECH PROJECT, 2023
** library MY_GRAPHICS
** File description:
** header for rect folder
*/
#ifndef MY_GRAPHICS_RECT
    #define MY_GRAPHICS_RECT
    #include <SFML/Graphics.h>
    /*
    ** =============================== RECT ================================
    */
    sfIntRect set_rectangle(int left, int top, int width, int height);
    sfIntRect next_rectangle(sfIntRect rectangle);

    #define NULL_RECT set_rectangle(0, 0, 0, 0)
#endif
