/*
** EPITECH PROJECT, 2022
** str_find.c
** File description:
** -> finds the first occurrence of a specific char / predicate in string
*/

#include <my.h>

char *str_find(char *str, char c)
{
    return my_strchr(str, c);
}

char *str_find_pred(char *str, bool (*predicate)(char))
{
    while (str && *str) {
        if (predicate(*str)) {
            return str;
        }
        str++;
    }
    return NULL;
}

char *str_rfind(char *str, char c)
{
    return my_strrchr(str, c);
}

char *str_rfind_pred(char *str, bool (*predicate)(char))
{
    char *end = str_back(str);

    while (end && end >= str) {
        if (predicate(*end)) {
            return end;
        }
        end--;
    }
    return NULL;
}
