/*
** EPITECH PROJECT, 2022
** my_string_insert.c
** File description:
** ->   function for inserting a char into a string
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>

char *str_back(char *str)
{
    return str + my_strlen(str) - 1;
}

char *cstr_padding(char *str, int length, int left_padding, char c)
{
    const int str_length = my_strlen(str);
    for (int i = 0; i < length - str_length; i++) {
        str = left_padding ? str_prepend(str, c) : str_append(str, c);
    }
    return str;
}

/*
    str_copy_and_realloc
        - Copies a string into another
        - Reallocs the destination if too small
        - But doesn't if not necessary (avoids useless mallocs)
        - NULL terminator is always added
*/
bool str_copy_and_realloc(char **str, char *new_str)
{
    const bool are_str_ok = str && *str && new_str;
    const size_t str_size = are_str_ok ? my_strlen(*str) : 0;
    const size_t new_str_size = are_str_ok ? my_strlen(new_str) : 0;

    RETURN_VALUE_IF(!are_str_ok, false);
    if (str_size < new_str_size) {
        free(*str);
        *str = my_calloc(new_str_size + 1);
        RETURN_VALUE_IF(!str, false);
    }
    my_strcpy(*str, new_str);
    for (size_t i = str_size; i < new_str_size; i++) {
        (*str)[i] = '\0';
    }
    return true;
}
