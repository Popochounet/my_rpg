/*
** EPITECH PROJECT, 2022
** read_arg.c
** File description:
** ->   reads from va_list
*/

#include <stdarg.h>
#include <sys/types.h>
#include <my.h>
#include "my_printf.h"
#include "read_arg.h"

int read_arg(types_t *arg, va_list args, flag_t *flag)
{
    if (char_in_wstr(L"di", flag->flag_struct->conversion_specifier)) {
        return cast_signed_integers(arg, flag, args);
    }
    if (char_in_wstr(L"uoxXb", flag->flag_struct->conversion_specifier)) {
        return cast_unsigned_integers(arg, flag, args);
    }
    if (char_in_wstr(L"fFeEgGaA", flag->flag_struct->conversion_specifier)) {
        return cast_floats(arg, flag, args);
    }
    if (char_in_wstr(L"sS", flag->flag_struct->conversion_specifier)) {
        return cast_strings(arg, args, flag);
    }
    if (char_in_wstr(L"%c", flag->flag_struct->conversion_specifier)) {
        return cast_chars(arg, args, flag);
    }
    return cast_pointers(arg, args, flag);
}
