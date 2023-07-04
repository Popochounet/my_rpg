/*
** EPITECH PROJECT, 2022
** str_array2.c
** File description:
** -> functions to work with arrays of strings
*/

#include <stddef.h>
#include <stdlib.h>
#include <my.h>
#include <my_macros.h>

void str_array_free(char **array, size_t length)
{
    for (size_t i = 0; array && i < length; i++) {
        FREE_IF_ALLOCATED(array[i], free);
    }
    FREE_IF_ALLOCATED(array, free);
}

char **copy_str_array(char **array)
{
    const size_t length = str_array_length(array);
    char **new_array = malloc(sizeof(char*) * (length + 1));
    bool status = new_array != NULL;
    size_t i = 0;

    if (status) {
        new_array[length] = NULL;
    }
    while (i < length && status) {
        new_array[i] = my_strdup(array[i]);
        status &= new_array[i++] != NULL;
    }
    if (!status && new_array != NULL) {
        for (size_t j = 0; j < i; j++) {
            free(new_array[j]);
        }
    }
    return status ? new_array : NULL;
}
