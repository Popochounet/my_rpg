/*
** EPITECH PROJECT, 2022
** flag_p.c
** File description:
** ->   puts an address
*/

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include <my.h>
#include "my_printf.h"

// recast correctly the pointer

static void flag_n_2(intmax_t *integer, int written, wchar_t *length_modifier)
{
    if (length_modifier == NULL) {
        *(int *)integer = written;
        return;
    }
    if (my_wstrcmp(length_modifier, L"z") == 0) {
        *(ssize_t *)integer = written;
        return;
    }
    if (my_wstrcmp(length_modifier, L"t") == 0) {
        *(ptrdiff_t *)integer = written;
        return;
    }
    *integer = written;
}

void flag_n(intmax_t *integer, int written, wchar_t *length_modfiers)
{
    if (my_wstrcmp(length_modfiers, L"hh") == 0) {
        *( signed char *)integer = written;
        return;
    }
    if (my_wstrcmp(length_modfiers, L"h") == 0) {
        *(short *)integer = written;
        return;
    }
    if (my_wstrcmp(length_modfiers, L"ll") == 0) {
        *(long long *)integer = written;
        return;
    }
    if (my_wstrcmp(length_modfiers, L"l") == 0) {
        *(long *)integer = written;
        return;
    }
    flag_n_2(integer, written, length_modfiers);
}
