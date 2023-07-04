/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** ->   looks for a substring into a string
*/

#include <stdlib.h>
#include <my.h>

int
does_substr_match(const wchar_t *str, const wchar_t *substr, unsigned start)
{
    if (!str || !substr) {
        return 0;
    }
    const unsigned substr_len = my_wstrlen(substr);
    const unsigned str_len = my_wstrlen(str);
    if (substr_len > str_len) {
        return 0;
    }
    for (unsigned i = 0; i < substr_len; i++) {
        if (*(str + start + i) != *(substr + i)) {
            return 0;
        }
    }
    return 1;
}

const wchar_t *my_wstrstr(const wchar_t *str, const wchar_t *to_find)
{
    if (!str || !to_find) {
        return str;
    }
    const unsigned str_len = my_wstrlen(str);
    if (str_len == 0) {
        return *to_find == '\0' ? str : NULL;
    }
    for (unsigned i = 0; i < str_len; i++) {
        if (does_substr_match(str, to_find, i)) {
            return str + i;
        }
    }
    return NULL;
}
