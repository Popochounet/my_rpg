/*
** EPITECH PROJECT, 2022
** convert_unsigned_integers.c
** File description:
** ->   reads unsigned integer from va_list
*/

#include <my.h>
#include "my_printf.h"

static uintmax_t cast_unsigned_ptrdiff_t(va_list args)
{
    if (sizeof(ptrdiff_t) == sizeof(char)) {
        return (unsigned char)va_arg(args, unsigned);
    }
    if (sizeof(ptrdiff_t) == sizeof(short)) {
        return (unsigned short)va_arg(args, unsigned);
    }
    if (sizeof(ptrdiff_t) == sizeof(int)) {
        return va_arg(args, unsigned);
    }
    if (sizeof(ptrdiff_t) == sizeof(long)) {
        return va_arg(args, unsigned long);
    }
    return va_arg(args, unsigned long long);
}

static uintmax_t cast_special_unsigned_integers(flag_t *flag, va_list args)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"z") == 0) {
        return va_arg(args, size_t);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"t") == 0) {
        return cast_unsigned_ptrdiff_t(args);
    }
    return va_arg(args, uintmax_t);
}

static uintmax_t cast_unsigned_integers_impl(flag_t *flag, va_list args)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        return (unsigned char)va_arg(args, unsigned);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        return (unsigned short)va_arg(args, unsigned);
    }
    if (flag->flag_struct->length_modifier == NULL) {
        return va_arg(args, unsigned);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"l") == 0) {
        return va_arg(args, unsigned long);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"ll") == 0) {
        return va_arg(args, unsigned long long);
    }
    return cast_special_unsigned_integers(flag, args);
}

int cast_unsigned_integers(types_t *arg, flag_t *flag, va_list args)
{
    arg->unsigned_int = cast_unsigned_integers_impl(flag, args);
    return 0;
}
