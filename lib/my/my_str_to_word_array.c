/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** ->   splits a string into a word array
*/

#include <stdlib.h>
#include <stdbool.h>
#include <my.h>

static bool is_delimiter(char c)
{
    return !('A' <= c && c <= 'Z') &&
            !('a' <= c && c <= 'z') &&
            !('0' <= c && c <= '9');
}

static unsigned count_non_alpha(const char *str)
{
    unsigned count = 0;
    while (str && *str) {
        count += is_delimiter(*str++);
    }
    return count;
}

static unsigned length_until_delimiter(const char *str)
{
    unsigned n = 0;
    while (str && *str && !is_delimiter(*str++)) {
        n++;
    }
    return n;
}

static char *extract_str_until_delimiter(const char **str)
{
    if (!(*str) || !(**str)) {
        return NULL;
    }
    while (*str && **str && is_delimiter(**str)) {
        (*str)++;
    }
    const unsigned length = length_until_delimiter(*str);
    char *next_string = malloc(sizeof(char) * (length + 1));
    for (unsigned i = 0; i <= length; i++) {
        *(next_string + i) = (i == length) ? '\0' : *((*str)++);
    }
    while (*str && **str && is_delimiter(**str)) {
        (*str)++;
    }
    return next_string;
}

char **my_str_to_word_array(const char *str)
{
    const unsigned spaces = count_non_alpha(str);
    char **word_array = malloc(sizeof(char *) * (spaces + 2));
    for (unsigned i = 0; i <= spaces; i++) {
        word_array[i] = !*str ? NULL : extract_str_until_delimiter(&str);
    }
    word_array[spaces + 1] = NULL;
    return word_array;
}
