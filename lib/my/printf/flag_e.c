/*
** EPITECH PROJECT, 2022
** float_e.c
** File description:
** ->   flag %e : displays floating-point number in scientific notation
*/

#include <stdlib.h>
#include <my.h>
#include <my_macros.h>
#include "my_printf.h"

short get_exp10(long double n)
{
    short exp = 0;
    if (n > 1.L) {
        while (n >= 10.L) {
            exp++;
            n /= 10.L;
        }
    } else {
        while (n < 1.L) {
            exp--;
            n *= 10.L;
        }
    }
    return exp;
}

static wchar_t *append_exponent(wchar_t *str, short exponent, int lower)
{
    wchar_t *const exp_str = my_wputnbr_base(ABS(exponent), L"0123456789");
    wchar_t *const zero_filled_exp_str = wstr_padding(exp_str, 2, 1, '0');
    str = wstr_append(str, lower ? 'e' : 'E');
    str = wstr_append(str, exponent < 0 ? '-' : '+');
    str = wstr_append_str(str, zero_filled_exp_str);
    free(zero_filled_exp_str);
    return str;
}

static
wchar_t *flag_e_impl(long double n, int decimals, int lower, int has_hashtag)
{
    wchar_t *str = NULL;
    wchar_t *positive_call = NULL;
    short exp = 0;

    if (n < 0.L) {
        str = wstr_append(str, '-');
        positive_call = flag_e_impl(-n, decimals, lower, has_hashtag);
        return wstr_append_str(str, positive_call);
    }
    exp = get_exp10(n);
    while (n >= 10.L) {
        n /= 10.L;
    }
    while (n < 1.L) {
        n *= 10.L;
    }
    str = flag_f(n, decimals, lower, has_hashtag);
    return append_exponent(str, exp, lower);
}

wchar_t *flag_e(long double n, int decimals, int lower, int has_hashtag)
{
    if (my_isnan(n)) {
        return my_wstrdup(L"-nan");
    } else if (my_isinf(n)) {
        return n < 0 ? my_wstrdup(L"-inf") : my_wstrdup(L"inf");
    } else {
        return flag_e_impl(n, decimals, lower, has_hashtag);
    }
}
