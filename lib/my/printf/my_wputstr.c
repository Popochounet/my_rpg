/*
** EPITECH PROJECT, 2022
** my_wputstr.c
** File description:
** ->   displays a string
** ->   allowed function : my_putchar
*/

#include <my.h>

int my_wputstr(const wchar_t *str)
{
    int length = 0;

    while (str && *str) {
        my_wputchar(*str++);
        length++;
    }
    return length;
}
