/*
** EPITECH PROJECT, 2022
** convert_signed_integers.c
** File description:
** ->   reads signed integer from va_list
*/

#include <sys/types.h>
#include <my.h>
#include "my_printf.h"

static intmax_t cast_special_signed_integers(flag_t *flag, va_list args)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"z") == 0) {
        return va_arg(args, ssize_t);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"t") == 0) {
        return va_arg(args, ptrdiff_t);
    }
    return va_arg(args, intmax_t);
}

static intmax_t cast_signed_integers_impl(flag_t *flag, va_list args)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        return ( signed char)va_arg(args, int);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        return (short)va_arg(args, int);
    }
    if (flag->flag_struct->length_modifier == NULL) {
        return va_arg(args, int);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"l") == 0) {
        return va_arg(args, long);
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"ll") == 0) {
        return va_arg(args, long long);
    }
    return cast_special_signed_integers(flag, args);
}

int cast_signed_integers(types_t *arg, flag_t *flag, va_list args)
{
    arg->signed_int = cast_signed_integers_impl(flag, args);
    return 0;
}
