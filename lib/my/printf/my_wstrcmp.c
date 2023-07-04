/*
** EPITECH PROJECT, 2022
** my_wstrcmp.c
** File description:
** ->   compares two strings
*/

#include <my.h>

int my_wstrcmp(const wchar_t *s1, const wchar_t *s2)
{
    if (!s1 || !s2) {
        return !s1 ? 1 : -1;
    }
    if (!*s1) {
        return !*s2 ? 0 : -1;
    } else if (!*s2) {
        return 1;
    }
    for (int i = 0;; i++) {
        const wchar_t c1 = *(s1 + i);
        const wchar_t c2 = *(s2 + i);
        if (!c1 || !c2) {
            return !c1 ? (!c2 ? 0 : -1) : 1;
        }
        if (c1 != c2) {
            return c1 - c2;
        }
    }
    return 0;
}
