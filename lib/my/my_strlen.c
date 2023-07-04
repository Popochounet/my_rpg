/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** ->   returns string length
** ->   allowed function : my_putchar
*/

#include <stddef.h>

size_t my_strlen(const char *str)
{
    size_t length = 0;
    while (str && *str++) {
        length++;
    }
    return length;
}
