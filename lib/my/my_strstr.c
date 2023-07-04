/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** ->   looks for a substring into a string
*/

#include <stdbool.h>
#include <my.h>

static bool does_substr_match
(const char *str, const char *substr, unsigned start)
{
    if (!str || !substr) {
        return false;
    }
    const unsigned substr_len = my_strlen((char *)substr);
    const unsigned str_len = my_strlen((char *)str);
    if (substr_len > str_len) {
        return false;
    }
    for (unsigned i = 0; i < substr_len; i++) {
        if (*(str + start + i) != *(substr + i)) {
            return false;
        }
    }
    return true;
}

char *my_strstr(char *str, const char *to_find)
{
    if (!str || !to_find) {
        return str;
    }
    const unsigned str_len = my_strlen(str);
    if (str_len == 0) {
        return *to_find == '\0' ? str : (void *)0;
    }
    for (unsigned i = 0; i < str_len; i++) {
        if (does_substr_match((const char *)str, to_find, i)) {
            return str + i;
        }
    }
    return (void *)0;
}
