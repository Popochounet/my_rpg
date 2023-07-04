/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** flag_d
*/

#include <limits.h>
#include <my.h>
#include "my_printf.h"

int get_int_precision(flag_t *flag)
{
    if (flag->flag_struct->is_precision_specified) {
        return flag->flag_struct->precision;
    }
    return -1;
}

static wchar_t *uint_to_wstr(uintmax_t n, wchar_t *str)
{
    if (n < 10) {
        str = wstr_append(str, '0' + n);
    } else {
        str = uint_to_wstr(n / 10, str);
        str = uint_to_wstr(n % 10, str);
    }
    return str;
}

static wchar_t *int_to_wstr(intmax_t n, wchar_t *str)
{
    if (n < 0) {
        str = wstr_prepend(str, '-');
        str = uint_to_wstr((uintmax_t)(-(n + 1)) + 1, str);
    } else {
        str = uint_to_wstr(n, str);
    }
    return str;
}

wchar_t *flag_di(intmax_t n, int precision)
{
    wchar_t *str = NULL;
    int str_length = 0;
    const int where_to_insert_zeros = n < 0;

    if (n == 0 && precision == 0) {
        return my_wstrdup(L"");
    }
    str = int_to_wstr(n, str);
    str_length = my_wstrlen(str) - where_to_insert_zeros;
    while (str_length < precision) {
        str = wstr_insert(str, where_to_insert_zeros, '0');
        str_length++;
    }
    return str;
}
