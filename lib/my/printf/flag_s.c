/*
** EPITECH PROJECT, 2022
** flag_p.c
** File description:
** ->   puts a string
*/

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <my.h>
#include "my_printf.h"

int get_str_precision(flag_t *flag)
{
    if (flag->flag_struct->is_precision_specified) {
        return flag->flag_struct->precision;
    }
    return INT_MAX;
}

wchar_t *flag_s(char *str, int precision)
{
    if (!str) {
        return precision == INT_MAX ? my_wstrdup(L"(null)") : my_wstrdup(L"");
    }
    wchar_t *wstr = my_wcalloc(my_strlen(str) + 1);
    for (int i = 0; i < precision && str[i]; i++) {
        wstr[i] = str[i];
    }
    return wstr;
}

wchar_t *wflag_s(wchar_t *wstr, int precision)
{
    if (!wstr) {
        return my_wstrdup(L"(null)");
    }
    return my_wstrndup(wstr, precision);
}

wchar_t *flag_upper_s(char *str)
{
    wchar_t *wstr = str_to_wstr(str);
    wchar_t *new_str = NULL;
    wchar_t *to_add = NULL;
    const wchar_t *const base = L"01234567";

    for (size_t i = 0; wstr && wstr[i]; i++) {
        if (wstr[i] < 32 || wstr[i] >= 127) {
            new_str = wstr_append(new_str, '\\');
            to_add = wstr_padding(my_wputnbr_base(wstr[i], base), 3, 1, '0');
            new_str = wstr_append_str(new_str, to_add);
            free(to_add);
            to_add = NULL;
        } else {
            new_str = wstr_append(new_str, wstr[i]);
        }
    }
    free(wstr);
    return new_str;
}
