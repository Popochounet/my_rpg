/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** ->   concats two strings
*/

#include <my.h>

char *my_strcat(char *dest, const char *src)
{
    const unsigned dest_size = dest ? my_strlen(dest) : 0;

    if (!dest || !src) {
        return NULL;
    }
    for (unsigned i = 0; src; i++) {
        if (!src[i]) {
            dest[dest_size + ++i] = '\0';
            break;
        }
        dest[dest_size + i] = src[i];
    }
    return dest;
}
