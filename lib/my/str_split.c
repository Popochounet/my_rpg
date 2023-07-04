/*
** EPITECH PROJECT, 2022
** str_split.c
** File description:
** -> splits a string according to a char or a predicate
*/

#include <my.h>

static char *extract_until_delim(char **str, char delim)
{
    char *const delim_pos = my_strchr(*str, delim);
    char *extracted = NULL;
    const size_t length = delim_pos - *str;

    if (!delim_pos) {
        return NULL;
    }
    extracted = str_substr(*str, 0, delim_pos - *str - 1);
    *str += length;
    return extracted;
}

char **str_split(char *str, char delim)
{
    char *const end = str_back(str);
    const size_t n_delims_end = end - str_rfind_not(str, delim);
    const size_t n_delims = str_count(str, delim) - n_delims_end;
    char **array = str_array_init(n_delims);

    if (!array) {
        return NULL;
    }
    for (size_t i = 0; i < n_delims; i++) {
        array[i] = extract_until_delim(&str, delim);
        while (*str == delim) {
            str++;
        }
    }
    return array;
}

static char *extract_until_pred(char **str, bool (*predicate)(char))
{
    char *const pred_pos = str_find_pred(*str, predicate);
    char *extracted = NULL;
    const size_t length = pred_pos - *str;

    if (!pred_pos) {
        return NULL;
    }
    extracted = str_substr(*str, 0, pred_pos - *str - 1);
    *str += length;
    return extracted;
}

char **str_split_pred(char *str, bool (*predicate)(char))
{
    char *const end = str_back(str);
    const size_t n_predicates_end = end - str_rfind_not_pred(str, predicate);
    const size_t n_delims = str_count_pred(str, predicate) - n_predicates_end;
    char **array = str_array_init(n_delims);

    if (!array) {
        return NULL;
    }
    for (size_t i = 0; i < n_delims; i++) {
        array[i] = extract_until_pred(&str, predicate);
        while (predicate(*str)) {
            str++;
        }
    }
    return array;
}
