/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** my_real_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <my.h>
#include "my_printf.h"
#include "call_flags.h"

static int format_and_print(wchar_t *str, flag_t *flag)
{
    int final_str_length = 0;

    str = apply_plus_and_space(str, flag);
    str = apply_hashtag(str, flag);
    str = apply_padding(str, flag);
    final_str_length = my_wputstr(str);
    free(str);
    return final_str_length;
}

static wchar_t *call_flag(flag_t *flag, types_t *arg)
{
    if (char_in_wstr(L"di", flag->flag_struct->conversion_specifier)) {
        return flag_di(arg->signed_int, get_int_precision(flag));
    }
    if (char_in_wstr(L"uoxX", flag->flag_struct->conversion_specifier)) {
        return call_unsigned(flag, arg);
    }
    if (char_in_wstr(L"fFeEgGaA", flag->flag_struct->conversion_specifier)) {
        return call_float(flag, arg);
    }
    if (flag->flag_struct->conversion_specifier == L's') {
        return call_string(flag, arg);
    }
    if (flag->flag_struct->conversion_specifier == L'c') {
        return call_char(flag, arg);
    }
    return call_additional_flags(flag, arg);
}

static int
perform_flag(const wchar_t *restrict *format, va_list args, int written)
{
    flag_t *flag = parse_flag(*format, args);
    types_t arg;
    int return_code = 0;

    if (!flag->is_good) {
        return my_wputstr(flag->flag_str);
    }
    read_arg(&arg, args, flag);
    if (flag->flag_struct->conversion_specifier == 'n') {
        flag_n(arg.flag_n_ptr, written, flag->flag_struct->length_modifier);
    } else if (flag->flag_struct->conversion_specifier == '%') {
        return_code = my_wputstr(L"%");
    } else {
        return_code = format_and_print(call_flag(flag, &arg), flag);
    }
    *format += my_wstrlen(flag->flag_str);
    free_flag(flag);
    return return_code;
}

int my_wvprintf(const wchar_t *restrict wformat, va_list args)
{
    int written = 0;

    while (*wformat) {
        if (*wformat != '%') {
            my_putchar(*wformat++);
            written++;
        } else {
            written += perform_flag(&wformat, args, written);
        }
    }
    return written;
}

int my_wprintf(const wchar_t *restrict wformat, ...)
{
    va_list args;
    int return_code = 0;
    wchar_t *copy_wformat = my_wstrdup(wformat);

    va_start(args, wformat);
    return_code = my_wvprintf(copy_wformat, args);
    va_end(args);
    free(copy_wformat);
    return return_code;
}
