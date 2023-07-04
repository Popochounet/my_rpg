/*
** EPITECH PROJECT, 2022
** str_count.c
** File description:
** -> counts the number of occurrences of a char or predicate filled in string
*/

#include <stdbool.h>
#include <stddef.h>

size_t str_count(char *str, char c)
{
    size_t n = 0;

    while (str && *str) {
        n += *str++ == c;
    }
    return n;
}

size_t str_count_pred(char *str, bool (*predicate)(char))
{
    size_t n = 0;

    while (str && *str) {
        n += predicate(*str++);
    }
    return n;
}
