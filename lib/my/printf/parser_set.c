/*
** EPITECH PROJECT, 2022
** parser_set.c
** File description:
**  ->  set flag struct's attributes when parsing it
*/

#include <stdarg.h>
#include <stdlib.h>
#include <my.h>
#include "my_printf.h"
#include "parser.h"

void free_flag(flag_t *flag)
{
    if (flag->flag_str) {
        free(flag->flag_str);
    }
    if (flag->flag_struct->length_modifier) {
        free(flag->flag_struct->length_modifier);
    }
    free(flag->flag_struct);
    free(flag);
}

void set_modifier(flag_struct_t *flag_struct, wchar_t c)
{
    flag_struct->has_hyphen |= c == '-';
    flag_struct->has_plus |= c == '+';
    flag_struct->has_space |= c == ' ';
    flag_struct->has_hashtag |= c == '#';
    flag_struct->has_zero |= c == '0';
}

unsigned set_field_width(const wchar_t *format, flag_t *flag, va_list args)
{
    unsigned count = 0;

    if (*format == '*') {
        flag->flag_struct->field_width = va_arg(args, int);
        return 1;
    }
    if (!wis_nonzero_digit(*format)) {
        return 0;
    }
    flag->flag_struct->field_width = my_wgetnbr(format);
    while (wis_digit(*format++)) {
        count++;
    }
    return count;
}

unsigned set_precision(const wchar_t *format, flag_t *flag, va_list args)
{
    unsigned count = 1;

    if (*format++ != '.') {
        flag->flag_struct->is_precision_specified = 0;
        return 0;
    }
    if (*format == '*') {
        flag->flag_struct->precision = va_arg(args, int);
        return 2;
    }
    flag->flag_struct->precision = wis_digit(*format) ? my_wgetnbr(format) : 0;
    while (wis_digit(*format++)) {
        count++;
    }
    return count;
}

unsigned set_length_modifier(const wchar_t *format, flag_t *flag)
{
    const wchar_t *const modifiers[8] = {
        L"hh", L"h", L"ll", L"l", L"j", L"z", L"t", L"L"
    };

    for (int i = 0; i < 8; i++) {
        if (does_substr_match(format, modifiers[i], 0)) {
            flag->flag_struct->length_modifier = my_wstrdup(modifiers[i]);
            return my_wstrlen(modifiers[i]);
        }
    }
    return 0;
}
