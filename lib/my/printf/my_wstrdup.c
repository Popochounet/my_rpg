/*
** EPITECH PROJECT, 2022
** my_wstrdup.c
** File description:
** ->   duplicates a string
*/

#include <my.h>
#include <stdlib.h>

static size_t min(size_t a, size_t b)
{
    return a < b ? a : b;
}

wchar_t *my_wstrndup(const wchar_t *src, size_t n)
{
    const size_t size = min(n, my_wstrlen(src)) + 1;
    wchar_t *copy = my_wcalloc(size);

    for (size_t i = 0; i < n && src[i]; i++) {
        copy[i] = src[i];
    }
    return copy;
}

wchar_t *my_wstrdup(const wchar_t *src)
{
    return my_wstrndup(src, my_wstrlen(src));
}
