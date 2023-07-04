/*
** EPITECH PROJECT, 2022
** str_advance.c
** File description:
** -> increase a pointer until specific value or condition reached / filled
*/

#include <stddef.h>
#include <stdbool.h>

size_t str_advance(char **ptr, size_t n)
{
    size_t i = 0;

    while (ptr && *ptr && **ptr && i++ < n) {
        (*ptr)++;
    }
    return i;
}

size_t str_advance_char(char **ptr, char c)
{
    size_t i = 0;

    while (ptr && *ptr && **ptr && **ptr == c && ++i) {
        (*ptr)++;
    }
    return i;
}

size_t str_advance_char_not(char **ptr, char c)
{
    size_t i = 0;

    while (ptr && *ptr && **ptr && **ptr != c && ++i) {
        (*ptr)++;
    }
    return i;
}

size_t str_advance_pred(char **ptr, bool (*predicate)(char))
{
    char *const copy_ptr = *ptr;

    while (ptr && *ptr && **ptr && predicate(**ptr)) {
        (*ptr)++;
    }
    return *ptr - copy_ptr;
}

size_t str_advance_pred_not(char **ptr, bool (*predicate)(char))
{
    char *const copy_ptr = *ptr;

    while (ptr && *ptr && **ptr && !predicate(**ptr)) {
        (*ptr)++;
    }
    return *ptr - copy_ptr;
}
