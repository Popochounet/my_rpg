/*
** EPITECH PROJECT, 2022
** call_core.c
** File description:
** ->   core functions for calling correct flags
*/

#include <wchar.h>
#include <my.h>
#include "my_printf.h"

wchar_t *call_unsigned(flag_t *flag, types_t *arg)
{
    const int hex_lower = flag->flag_struct->conversion_specifier == 'x';
    const int int_precision = get_int_precision(flag);

    if (flag->flag_struct->conversion_specifier == 'u') {
        return flag_u(arg->unsigned_int, int_precision);
    }
    if (flag->flag_struct->conversion_specifier == 'o') {
        return flag_o(arg->unsigned_int, int_precision);
    }
    return flag_x(arg->unsigned_int, hex_lower, int_precision);
}

wchar_t *call_float(flag_t *flag, types_t *arg)
{
    wchar_t *(*const flags[4])(long double, int, int, int) = {
        flag_f, flag_e, flag_g, flag_a
    };
    const wchar_t *const str = L"fega";
    wchar_t *result = NULL;
    int lower;

    for (int i = 0; i < 4; i++) {
        if (str[i] == wto_lower(flag->flag_struct->conversion_specifier)) {
            lower = flag->flag_struct->conversion_specifier == str[i];
            result = flags[i](
                arg->floating_point,
                flag->flag_struct->precision,
                lower, flag->flag_struct->has_hashtag
            );
            break;
        }
    }
    return result;
}

wchar_t *call_string(flag_t *flag, types_t *arg)
{
    const int precision = get_str_precision(flag);

    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        return flag_s(arg->str, precision);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        return flag_s(arg->str, precision);
    }
    if (flag->flag_struct->length_modifier == NULL) {
        return flag_s(arg->str, precision);
    }
    return wflag_s(arg->wstr, precision);
}

wchar_t *call_char(flag_t *flag, types_t *arg)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        return flag_c(arg->char_);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        return flag_c(arg->char_);
    }
    if (flag->flag_struct->length_modifier == NULL) {
        return flag_c(arg->char_);
    }
    return wflag_c(arg->wchar);
}

wchar_t *call_additional_flags(flag_t *flag, types_t *arg)
{
    if (flag->flag_struct->conversion_specifier == '%') {
        return my_wstrdup(L"%");
    }
    if (flag->flag_struct->conversion_specifier == 'b') {
        return flag_b(arg->unsigned_int);
    }
    if (flag->flag_struct->conversion_specifier == 'p') {
        return flag_p(arg->flag_p_ptr);
    }
    return flag_upper_s(arg->str);
}
