/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** ->   concats n bytes of a string into another one
*/

#include <my.h>

static void fill_str_null_chars(char *str, int nb)
{
    while (nb--) {
        *str++ = '\0';
    }
}

char *my_strncat(char *dest, const char *src, int nb)
{
    const unsigned dest_size = my_strlen(dest);
    for (int i = 0; src && nb > 0 && i < nb; i++) {
        if (!*(src + i)) {
            fill_str_null_chars(dest + dest_size + i, nb - i);
            break;
        }
        *(dest + dest_size + i) = *(src + i);
    }
    return dest;
}
