/*
** EPITECH PROJECT, 2022
** str_array.c
** File description:
** -> functions to work with arrays of strings
*/

#include <my.h>
#include <stdlib.h>

size_t str_array_length(char **const array)
{
    size_t length = 0;

    while (array && array[length]) {
        length++;
    }
    return length;
}

char **str_array_append(char **array, char *str)
{
    char **new_array = malloc((str_array_length(array) + 2) * sizeof(char *));
    size_t i = 0;

    while (new_array && array && array[i]) {
        new_array[i] = array[i];
        i++;
    }
    if (new_array) {
        new_array[i++] = str;
        new_array[i] = NULL;
    }
    if (array) {
        free(array);
    }
    return new_array;
}

char **make_str_array(char *str)
{
    char **array = malloc(2 * sizeof(char *));

    if (array) {
        array[0] = str;
        array[1] = NULL;
    }
    return array;
}

char **str_array_extend(char **array, char **add)
{
    const size_t add_len = str_array_length(add);
    const size_t total_size = str_array_length(array) + add_len;
    char **new_array = malloc((total_size + 1) * sizeof(char *));
    size_t array_index = 0;

    for (size_t i = 0; new_array && array && array[i]; i++) {
        new_array[array_index++] = array[i];
    }
    for (size_t i = 0; new_array && add && i <= add_len; i++) {
        new_array[array_index++] = add[i];
    }
    if (array) {
        free(array);
    }
    if (add) {
        free(add);
    }
    return new_array;
}

char **str_array_init(size_t n_strings)
{
    char **array = malloc(sizeof(char *) * n_strings);

    for (size_t i = 0; array && i < n_strings; i++) {
        array[i] = NULL;
    }
    return array;
}
