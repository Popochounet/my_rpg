/*
** EPITECH PROJECT, 2022
** my_wcalloc.c
** File description:
** ->   calloc allocates a string and fills it with '\0's
*/

#include <stddef.h>
#include <stdlib.h>

wchar_t *my_wcalloc(size_t length)
{
    wchar_t *str = malloc(sizeof(wchar_t) * length);

    for (size_t i = 0; str && i < length; i++) {
        str[i] = '\0';
    }
    return str;
}
