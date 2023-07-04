/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** ->   checks whether a string only has alpha chars or not
*/

#include <stdbool.h>

bool my_isalpha(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool my_str_isalpha(const char *str)
{
    if (!str) {
        return 0;
    }
    for (int i = 0; *(str + i); i++) {
        const char c = *(str + i);
        if (!my_isalpha(c)) {
            return 0;
        }
    }
    return 1;
}
