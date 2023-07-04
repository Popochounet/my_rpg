/*
** EPITECH PROJECT, 2022
** apply_modifiers.c
** File description:
** ->   apply modifiers on buffer returned by flagXX functions
*/

#include <my.h>
#include "my_printf.h"

wchar_t *apply_hashtag(wchar_t *str, flag_t *flag)
{
    if (!flag->flag_struct->has_hashtag) {
        return str;
    }
    if (char_in_wstr(L"fFeEgGaA", flag->flag_struct->conversion_specifier)) {
        return my_wstrstr(str, L".") ? str : wstr_append(str, '.');
    }
    if (!char_in_wstr(L"oxX", flag->flag_struct->conversion_specifier)) {
        return str;
    }
    if (flag->flag_struct->conversion_specifier != 'o') {
        str = wstr_prepend(str, flag->flag_struct->conversion_specifier);
    }
    return *str == '0' ? str : wstr_prepend(str, '0');
}

wchar_t *apply_plus_and_space(wchar_t *str, flag_t *flag)
{
    if (char_in_wstr(L"csnbS%", flag->flag_struct->conversion_specifier)) {
        return str;
    }
    if (!char_in_wstr(L"uoxX", flag->flag_struct->conversion_specifier)) {
        if (flag->flag_struct->has_space && !my_wstrstr(str, L"-")) {
            return wstr_prepend(str, ' ');
        }
    }
    if (!char_in_wstr(L"difFeEgGaA", flag->flag_struct->conversion_specifier)) {
        return str;
    }
    if (*str != '-' && flag->flag_struct->has_plus) {
        str = wstr_prepend(str, '+');
    }
    return str;
}

static int where_to_insert_padding(wchar_t *str, flag_t *flag, wchar_t c)
{
    int n = 0;

    if (flag->flag_struct->has_hyphen) {
        return my_wstrlen(str);
    }
    if (flag->flag_struct->conversion_specifier == 's') {
        return 0;
    }
    n += c == '0' && (*str == '+' || *str == '-');
    if (*str == '0' && (str[1] == 'x' || str[1] == 'X')) {
        n += 2;
    }
    return n;
}

static wchar_t char_for_padding(flag_t *flag)
{
    int is_zero = flag->flag_struct->has_zero;
    is_zero *= !flag->flag_struct->has_hyphen;
    is_zero *= !char_in_wstr(L"%csSn", flag->flag_struct->conversion_specifier);
    return is_zero ? '0' : ' ';
}

wchar_t *apply_padding(wchar_t *str, flag_t *flag)
{
    const wchar_t padding_char = char_for_padding(flag);
    const int index = where_to_insert_padding(str, flag, padding_char);
    int str_length = my_wstrlen(str);

    if (padding_char == '0' && *str == '0') {
        return str;
    }
    while (str_length++ < flag->flag_struct->field_width) {
        str = wstr_insert(str, index, padding_char);
    }
    return str;
}
