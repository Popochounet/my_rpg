/*
** EPITECH PROJECT, 2022
** cast_floats.c
** File description:
** ->   converts both float types from va_list
*/

#include <stdarg.h>
#include <my.h>
#include "my_printf.h"

int cast_floats(types_t *arg, flag_t *flag, va_list args)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"L") == 0) {
        arg->floating_point = va_arg(args, long double);
        return 0;
    }
    arg->floating_point = va_arg(args, double);
    return 0;
}
