/*
** EPITECH PROJECT, 2022
** my_string_insert.c
** File description:
** ->   function for inserting a char into a string
*/

#include <my.h>
#include "printf/my_printf.h"
#include <stdlib.h>

char *str_insert(char *str, int index, char c)
{
    const int length = my_strlen(str);
    char *new_str = my_calloc(length + 2);
    int has_inserted = 0;

    if (index < 0) {
        index = 0;
    } else if (index >= length) {
        index = length;
    }
    for (int i = 0; i < length + 1; i++) {
        if (i == index) {
            new_str[i] = c;
            has_inserted = 1;
        }
        new_str[i + has_inserted] = str[i];
    }
    free(str);
    return new_str;
}

char *str_pop(char *str, size_t index)
{
    const size_t length = my_strlen(str);
    char *new_str = my_calloc(length - 1);

    for (size_t i = 0; i < length; i++) {
        if (i != index) {
            new_str = str_append(new_str, str[i]);
        }
    }
    free(str);
    return new_str;
}

char *cstr_substr(char *str, size_t start, size_t count)
{
    char *substr = my_calloc(start + count + 1);

    for (size_t i = 0; i < count; i++) {
        substr[i] = str[start + i];
    }
    return substr;
}

char *str_substr(char *str, size_t start, size_t count)
{
    char *substr = cstr_substr(str, start, count);

    free(str);
    return substr;
}
