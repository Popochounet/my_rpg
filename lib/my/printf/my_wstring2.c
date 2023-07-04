/*
** EPITECH PROJECT, 2022
** my_string_insert.c
** File description:
** ->   function for inserting a char into a string
*/

#include <stdlib.h>
#include <my.h>
#include "my_printf.h"

wchar_t *wstr_insert(wchar_t *str, int index, wchar_t c)
{
    const int length = my_wstrlen(str);
    wchar_t *new_str = my_wcalloc(length + 2);
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

wchar_t *wstr_pop(wchar_t *str, size_t index)
{
    const size_t length = my_wstrlen(str);
    wchar_t *new_str = my_wcalloc(length - 1);

    for (size_t i = 0; i < length; i++) {
        if (i != index) {
            new_str = wstr_append(new_str, str[i]);
        }
    }
    free(str);
    return new_str;
}
