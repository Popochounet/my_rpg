/*
** EPITECH PROJECT, 2022
** str_find.c
** File description:
** -> finds the first occurrence of a specific char / predicate in string
*/

#include <stdbool.h>
#include <my.h>

char *str_find_not(char *str, char c)
{
    while (str && *str && *str == c) {
        str++;
    }
    return (str && *str) ? str : NULL;
}

char *str_find_not_pred(char *str, bool (*predicate)(char))
{
    while (str && *str && predicate(*str)) {
        str++;
    }
    return (str && *str) ? str : NULL;
}

char *str_rfind_not(char *str, char c)
{
    char *end = str_back(str);

    while (end && end >= str) {
        if (*end != c) {
            return end;
        }
        end--;
    }
    return NULL;
}

char *str_rfind_not_pred(char *str, bool (*predicate)(char))
{
    char *end = str_back(str);

    while (end && end >= str) {
        if (!predicate(*end)) {
            return end;
        }
        end--;
    }
    return NULL;
}
