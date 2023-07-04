/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** ->   flag parser
*/

#include <stdlib.h>
#include <stdarg.h>
#include <my.h>
#include "my_printf.h"
#include "parser.h"

const int DEFAULT_FIELD_WIDTH = -1;

static unsigned set_conversion_specifier(const wchar_t *format, flag_t *flag)
{
    const wchar_t *const specifiers = L"GAfFcaudEXexposingbS%";
    for (int i = 0; specifiers[i]; i++) {
        if (*format == specifiers[i]) {
            flag->flag_struct->conversion_specifier = *format;
            return 1;
        }
    }
    return 0;
}

static void copy_bad_flag(const wchar_t *format, wchar_t **buf)
{
    const wchar_t *const specifiers = L"GAfFcaudEXexposingbS%";
    const wchar_t *const length_modifiers = L"hljztL";
    while (*format) {
        if (!char_in_wstr(length_modifiers, *format)) {
            *buf = wstr_append(*buf, *format);
        }
        if (char_in_wstr(specifiers, *format)) {
            break;
        }
        format++;
    }
}

static flag_struct_t *initialize_flag_struct(void)
{
    flag_struct_t *flag_struct = malloc(sizeof(flag_struct_t));

    if (flag_struct) {
        flag_struct->has_hyphen = 0;
        flag_struct->has_plus = 0;
        flag_struct->has_space = 0;
        flag_struct->has_hashtag = 0;
        flag_struct->has_zero = 0;
        flag_struct->field_width = DEFAULT_FIELD_WIDTH;
        flag_struct->precision = DEFAULT_PRECISION;
        flag_struct->is_precision_specified = 1;
        flag_struct->length_modifier = NULL;
        flag_struct->conversion_specifier = '\0';
    }
    return flag_struct;
}

static flag_t *initialize_flag_t(void)
{
    flag_t *flag = malloc(sizeof(flag_t));

    if (flag) {
        flag->flag_str = NULL;
        flag->is_good = 1;
        flag->flag_struct = initialize_flag_struct();
    }
    return flag;
}

flag_t *parse_flag(const wchar_t *format, va_list args)
{
    const wchar_t *const copy_format = format;
    flag_t *flag = initialize_flag_t();

    if (flag) {
        for (format++; wis_modifier(*format); format++) {
            set_modifier(flag->flag_struct, *format);
        }
        format += set_field_width(format, flag, args);
        format += set_precision(format, flag, args);
        format += set_length_modifier(format, flag);
        format += set_conversion_specifier(format, flag);
        if (!flag->flag_struct->conversion_specifier) {
            flag->is_good = 0;
            copy_bad_flag(copy_format, &flag->flag_str);
        } else {
            flag->flag_str = my_wstrndup(copy_format, format - copy_format);
        }
    }
    return flag;
}
