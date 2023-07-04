/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** ->   calloc allocates a string and fills it with '\0's
*/

#include <stddef.h>
#include <stdlib.h>

char *my_calloc(size_t length)
{
    char *str = malloc(sizeof(char) * length);

    for (size_t i = 0; str && i < length; i++) {
        str[i] = '\0';
    }
    return str;
}

void **my_calloc_pointers(size_t type_size, size_t n_elements)
{
    void **array = malloc(type_size * ++n_elements);

    for (size_t i = 0; array && i < n_elements; i++) {
        array[i] = NULL;
    }
    return array;
}
