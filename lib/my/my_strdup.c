/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** ->   cduplicates a string
*/

#include <stdlib.h>
#include <my.h>

/*
    RETURNS :
        - a malloc'd copy of the n first characters of str
        - NULL if str is NULL or memory allocation failed
    NOTE :
        - no extra NULL terminator is added if the n-th char of str is a NULL
            terminator.
        - OTHERWISE one will be added, so the string returned will be of
            size n + 1
*/
char *my_strndup(const char *str, size_t n)
{
    const bool does_str_have_null_terminator = str[n - 1] == '\0';
    char *copy = str ? my_calloc(n + !does_str_have_null_terminator) : NULL;

    if (!str || !copy) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        copy[i] = str[i];
    }
    return copy;
}

/*
    RETURNS :
        - a malloc'd copy of str
        - NULL if str is NULL or memory allocation failed
    NOTE :
        - NULL terminator is always added
*/
char *my_strdup(const char *str)
{
    return my_strndup(str, my_strlen(str));
}
