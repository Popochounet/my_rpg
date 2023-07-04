/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** ->   puts a string in uppercase
*/

#include <stdbool.h>
#include <my.h>

static bool is_special_char(char c)
{
    const char *special = "<>,?;.:/!%^¨*+-/=}])@_\\`|-[({'\"#~& ";
    for (unsigned i = 0; i < 37; i++) {
        if (*(special + i) == c) {
            return true;
        }
    }
    return false;
}

char *my_strcapitalize(char *str)
{
    if (!str || !*str) {
        return str;
    }
    int is_special_before = is_special_char(str[0]);
    for (size_t i = 0; i < my_strlen(str); i++) {
        const char c = *(str + i);
        if (!is_special_char(c) && (is_special_before || i == 0)) {
            *(str + i) = my_toupper(c);
            is_special_before = 0;
            continue;
        }
        if (is_special_char(c)) {
            is_special_before = 1;
        } else {
            *(str + i) = my_tolower(c);
        }
    }
    return str;
}
