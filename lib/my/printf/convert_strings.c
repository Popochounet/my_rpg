/*
** EPITECH PROJECT, 2022
** convert_string.c
** File description:
** ->   reads a string from va_list
*/

#include <stdarg.h>
#include <my.h>
#include "my_printf.h"

int cast_strings(types_t *arg, va_list args, flag_t *flag)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        arg->str = va_arg(args, char *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        arg->str = va_arg(args, char *);
        return 0;
    }
    if (flag->flag_struct->length_modifier == NULL) {
        arg->str = va_arg(args, char *);
        return 0;
    }
    arg->wstr = va_arg(args, wchar_t *);
    return 0;
}

int cast_chars(types_t *arg, va_list args, flag_t *flag)
{
    if (flag->flag_struct->conversion_specifier == '%') {
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        arg->char_ = (char)va_arg(args, int);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        arg->char_ = (char)va_arg(args, int);
        return 0;
    }
    if (flag->flag_struct->length_modifier == NULL) {
        arg->char_ = (char)va_arg(args, int);
        return 0;
    }
    arg->wchar = va_arg(args, wchar_t);
    return 0;
}
