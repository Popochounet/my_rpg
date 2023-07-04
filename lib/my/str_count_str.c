/*
** EPITECH PROJECT, 2023
** str_count_str.c
** File description:
** -> Functions to count the occurrences of a substring in a string
*/

#include <my.h>

size_t str_count_str(char *str, char *substr)
{
    const size_t str_len = my_strlen(str);
    const size_t substr_len = my_strlen(substr);
    size_t count = 0;
    bool does_substr_matches = false;

    for (size_t i = 0; i <= str_len - substr_len; i++) {
        does_substr_matches = true;
        for (size_t j = 0; does_substr_matches && j < substr_len; j++) {
            does_substr_matches &= str[i + j] == substr[j];
        }
        count += does_substr_matches;
    }
    return count;
}

size_t str_count_str_no_overlap(char *str, char *substr)
{
    const size_t str_len = my_strlen(str);
    const size_t substr_len = my_strlen(substr);
    size_t len = str_len - substr_len;
    size_t count = 0;
    bool does_substr_matches = true;
    size_t i = 0;
    while (i <= len) {
        size_t j = 0;
        while (does_substr_matches && j < substr_len) {
            does_substr_matches &= str[i + j] == substr[j];
            j++;
        }
        count += does_substr_matches;
        i += does_substr_matches * (substr_len - 1) + 1;
        does_substr_matches = true;
    }
    return count;
}

size_t str_ncount_str
(char *str, size_t str_len, size_t substr_start, size_t substr_length)
{
    size_t count = 0;
    bool does_substr_matches = false;

    for (size_t i = 0; i <= str_len - substr_length; i++) {
        does_substr_matches = true;
        for (size_t j = 0; does_substr_matches && j < substr_length; j++) {
            does_substr_matches &= str[i + j] == str[substr_start + j];
        }
        count += does_substr_matches;
    }
    return count;
}

size_t str_ncount_str_no_overlap
(char *str, size_t str_len, size_t substr_start, size_t substr_len)
{
    size_t count = 0;
    bool does_substr_matches = false;

    for (size_t i = 0; i <= str_len - substr_len; i++) {
        does_substr_matches = true;
        for (size_t j = 0; does_substr_matches && j < substr_len; j++) {
            does_substr_matches &= str[i + j] == str[substr_start + j];
        }
        count += does_substr_matches;
        i += does_substr_matches * (substr_len - 1);
    }
    return count;
}
