/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** ->   reverses a string
*/

#include <my.h>

char *my_revstr(char *str)
{
    const unsigned str_length = (unsigned)my_strlen(str);
    for (unsigned i = 0; str && i < str_length / 2; i++) {
        const char tmp = *(str + i);
        *(str + i) = *(str + str_length - i - 1);
        *(str + str_length - i - 1) = tmp;
    }
    return str;
}
