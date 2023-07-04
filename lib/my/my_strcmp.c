/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** ->   compares two strings
*/

#include <my.h>

int my_strcmp(const char *s1, const char *s2)
{
    if (!s1 || !s2) {
        return 0;
    }
    if (!*s1) {
        return !*s2 ? 0 : -1;
    } else if (!*s2) {
        return 1;
    }
    for (int i = 0;; i++) {
        const char c1 = *(s1 + i);
        const char c2 = *(s2 + i);
        if (!c1 || !c2) {
            return !c1 ? (!c2 ? 0 : -1) : 1;
        }
        if (c1 != c2) {
            return c1 - c2;
        }
    }
    return 0;
}
