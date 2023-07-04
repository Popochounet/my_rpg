/*
** EPITECH PROJECT, 2022
** my_wgetnbr_core.c
** File description:
** ->   core functions for get_nbr.c
*/

#include <wchar.h>
#include <limits.h>

int is_wchar_valid_in_nbr(wchar_t c)
{
    return (c >= '0' && c <= '9') || (c == '-' || c == '+');
}

int my_wnbr_strlen(const wchar_t *str)
{
    int length = 0;
    while (str && is_wchar_valid_in_nbr(*str)) {
        length++;
        str++;
    }
    return length;
}
