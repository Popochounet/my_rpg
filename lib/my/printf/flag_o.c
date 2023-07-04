/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** flag_o
*/

#include <stdio.h>
#include <my.h>
#include "my_printf.h"

wchar_t *flag_o(uintmax_t n, int precision)
{
    wchar_t *str = NULL;
    int str_length = 0;

    if (precision == 0 && n == 0) {
        return my_wstrdup(L"");
    }
    str = u_my_wputnbr_base(n, L"01234567");
    str_length = my_wstrlen(str);
    while (str_length++ < precision) {
        str = wstr_prepend(str, '0');
    }
    return str;
}
