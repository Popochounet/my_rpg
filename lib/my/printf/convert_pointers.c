/*
** EPITECH PROJECT, 2022
** convert_poiters.c
** File description:
** ->   reads pointer from va_list
*/

#include <stdarg.h>
#include <sys/types.h>
#include <my.h>
#include "my_printf.h"

static int cast_n_pointer(types_t *arg, va_list args, flag_t *flag)
{
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"l") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, long *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"ll") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, long long *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"z") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, ssize_t *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"t") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, ptrdiff_t *);
        return 0;
    }
    arg->flag_n_ptr = va_arg(args, intmax_t *);
    return 0;
}

int cast_pointers(types_t *arg, va_list args, flag_t *flag)
{
    if (flag->flag_struct->conversion_specifier == L'p') {
        arg->flag_p_ptr = va_arg(args, void *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"hh") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, signed char *);
        return 0;
    }
    if (my_wstrcmp(flag->flag_struct->length_modifier, L"h") == 0) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, short *);
        return 0;
    }
    if (flag->flag_struct->length_modifier == NULL) {
        arg->flag_n_ptr = (intmax_t *)va_arg(args, int *);
        return 0;
    }
    return cast_n_pointer(arg, args, flag);
}
