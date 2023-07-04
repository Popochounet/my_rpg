/*
** EPITECH PROJECT, 2022
** my_string_append_str.c
** File description:
** -> append a string to another one
*/

#include <stdlib.h>
#include <my.h>

char *cstr_append_cstr(char *str, char *to_add)
{
    const int str_length = str ? my_strlen(str) : 0;
    const int to_add_length = to_add ? my_strlen(to_add) : 0;
    char *new_str = my_calloc(str_length + to_add_length + 1);

    for (int i = 0; i < str_length; i++) {
        new_str[i] = str[i];
    }
    for (int i = 0; i < to_add_length; i++) {
        new_str[str_length + i] = to_add[i];
    }
    return new_str;
}

char *cstr_append_str(char *str, char *to_add)
{
    char *const result = cstr_append_cstr(str, to_add);

    free(to_add);
    return result;
}

char *str_append_cstr(char *str, char *to_add)
{
    char *const result = cstr_append_cstr(str, to_add);

    free(str);
    return result;
}

char *str_append_str(char *str, char *to_add)
{
    char *const result = cstr_append_cstr(str, to_add);

    free(str);
    free(to_add);
    return result;
}
