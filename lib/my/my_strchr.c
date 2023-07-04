/*
** EPITECH PROJECT, 2022
** my_strchr.c
** File description:
** -> Returns a pointer to the first occurence of a char in a string
*/

#include <my.h>

char *my_strnchr(char *str, size_t n, char c)
{
    for (size_t i = 0; i < n; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    return NULL;
}

char *my_strchr(char *str, char c)
{
    for (size_t i = 0; str && str[i]; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    return NULL;
}

char *my_strrchr(char *str, char c)
{
    char *end = str_back(str);

    while (end && end >= str) {
        if (*end == c) {
            return end;
        }
        end--;
    }
    return NULL;
}
