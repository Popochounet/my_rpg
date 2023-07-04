/*
** EPITECH PROJECT, 2023
** str_merge.c
** File description:
** -> A variadic function to merge multiple strings into a malloc'd one
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <my.h>
#include <my_macros.h>

static size_t calculate_total_str_size(unsigned n, va_list args)
{
    size_t size = 0;

    while (n--) {
        size += my_strlen(va_arg(args, char*));
    }
    return size;
}

static char *allocate_str(unsigned n, size_t size, va_list args)
{
    char *result = my_calloc(size + 1);
    size_t end_index = 0;
    char *str = NULL;

    RETURN_VALUE_IF(!result, NULL);
    while (n--) {
        str = va_arg(args, char*);
        my_strcpy(&result[end_index], str);
        end_index += my_strlen(str);
    }
    result[end_index] = '\0';
    return result;
}

/*
    Merges multiple strings into one :
        - n is the NUMBER of strings
        - ... MUST be n strings
            (if more, the last ones will be discarded)
            (if less, undefined behaviour)

    RETURNS a malloc'd string which is a concatenation of the args
*/
char *str_merge(unsigned n, ...)
{
    va_list args;
    va_list copy;
    size_t length = 0;
    char *str = NULL;

    va_start(args, n);
    va_copy(copy, args);
    length = calculate_total_str_size(n, args);
    va_end(args);
    str = allocate_str(n, length, copy);
    va_end(copy);
    return str;
}

char *str_merge_array(char **array)
{
    const size_t len = str_array_length(array);
    size_t *lengths = array ? malloc(sizeof(size_t)) : NULL;
    size_t total_len = 0;
    char *str = NULL;
    bool status = array && lengths;
    char *copy = NULL;

    for (size_t i = 0; status && i < len; i++) {
        lengths[i] = my_strlen(array[i]);
        total_len += lengths[i];
    }
    status &= (str = my_calloc(total_len + 1)) != NULL;
    copy = str;
    for (size_t i = 0; status && str && i < len; i++) {
        my_strcpy(str, array[i]);
        str += lengths[i];
    }
    return copy;
}

/*
    Merges all strings into one :
        - str MUST have enough space to concat all strings in
        - n is the number of strings
        - ... MUST be n strings
            (if more, the last ones will be discarded)
            (if less, undefined behaviour)
*/
void str_merge_in_place(char *str, unsigned n, ...)
{
    va_list args;
    size_t end_index = 0;
    char *va_str = NULL;

    va_start(args, n);
    while (n--) {
        va_str = va_arg(args, char*);
        my_strcpy(&str[end_index], va_str);
        end_index += my_strlen(va_str);
    }
    str[end_index] = '\0';
    va_end(args);
}
