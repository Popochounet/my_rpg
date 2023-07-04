/*
** EPITECH PROJECT, 2022
** str_append.c
** File description:
** ->
*/

#include <stdlib.h>
#include <my.h>

char *cstr_append(char *str, char c)
{
    const int length = my_strlen(str);
    char *new_str = my_calloc(length + 2);

    for (int i = 0; i < length; i++) {
        new_str[i] = str[i];
    }
    new_str[length] = c;
    return new_str;
}

char *str_append(char *str, char c)
{
    char *result = cstr_append(str, c);

    free(str);
    return result;
}

char *cstr_prepend(char *str, char c)
{
    const int length = my_strlen(str);
    char *new_str = my_calloc(length + 2);

    new_str[0] = c;
    for (int i = 0; i < length; i++) {
        new_str[i + 1] = str[i];
    }
    return new_str;
}

char *str_prepend(char *str, char c)
{
    char *result = cstr_prepend(str, c);

    free(str);
    return result;
}
