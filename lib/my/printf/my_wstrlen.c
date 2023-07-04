/*
** EPITECH PROJECT, 2022
** my_strlen_zu.c
** File description:
** ->   returns string length
*/

#include <wchar.h>

size_t my_wstrlen(const wchar_t *str)
{
    size_t length = 0;
    while (str && *str++) {
        length++;
    }
    return length;
}
